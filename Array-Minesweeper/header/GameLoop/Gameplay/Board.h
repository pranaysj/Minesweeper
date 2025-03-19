#pragma once
#include <SFML/Graphics.hpp>
#include<random>
#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/GameLoop/Gameplay/GameplayManager.h"

namespace Gameplay {

    class GameplayManager;

    enum class BoardState
    {
        FIRST_CELL,
        PLAYING,
        COMPLETED,
    };

	class Board {
    private:

        const float boardWidth = 866.f;
        const float boardHeight = 1080.f;
        const float boardPosition = 530.f;

        static const int numberOfRows = 9;
        static const int numberOfColumns = 9;

        const float horizontalCellPadding = 115.f;
        const float verticalCellPadding = 329.f;

        std::default_random_engine randomEngine;
        std::random_device randomDevice;

        int minesCount = 9;

        const std::string boardTexturePath = "assets/textures/board.png";
        sf::Texture boardTexture;
        sf::Sprite boardSprite;

        Cell* cell[numberOfRows][numberOfColumns];

        GameplayManager* gameplay_manager;

        BoardState boardState;

        void initialize(GameplayManager* gameplay_manager);
        void initializeBoardImage();
        void initializeVariables(GameplayManager* gameplay_manager);

        void createBoard();

        float getCellWidthInBoard() const;
        float getCellHeightInBoard() const;

        void populateBoard(sf::Vector2i cell_position);
        void populateMines(sf::Vector2i first_cell_position);
        void populateCell();

        int countMinesAround(sf::Vector2i cell_postion);
        bool isvalidCellPosition(sf::Vector2i cell_position);

        void openCell(sf::Vector2i position);
        
        int flaggedCells;
        void toggleFlag(sf::Vector2i position);

        void processCellType(sf::Vector2i cell_position);
        void processEmptyType(sf::Vector2i cell_position);
        void processMineCell(sf::Vector2i cell_position);

        bool isInvalidMinePosition(sf::Vector2i first_cell_position, int x, int y);

    public:
        Board(GameplayManager* gameplay_manager);

        void update(Event::EventPollingManager& event_manager);

        void render(sf::RenderWindow& window);

        void onCellButtonClicked(sf::Vector2i cell_position, MouseButtonType mouse_button_type);

        void revealAllMines();

        BoardState getBoardState();
        void setBoardState(BoardState state);
        
        bool areAllCellsOpen();
        void flagAllMine();

        int getRemainingMinesCount() const;

	};
}