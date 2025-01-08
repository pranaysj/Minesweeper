#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Sound/SoundManager.h"

namespace Gameplay
{
    class GameplayManager;

    class Board
    {
    private:
        GameplayManager* gameplay_manager;
        // Board Constants
        static const int numberOfRows = 9;
        static const int numberOfColumns = 9;
        static const int minesCount = 9;

        // State and View Members
        Cell* board[numberOfRows][numberOfColumns];
        int flaggedCells;

        const float horizontalCellPadding = 115.f;
        const float verticalCellPadding = 329.f;

        // Board Rendering
        const float boardWidth = 866.f;
        const float boardHeight = 1080.f;
        const float boardPosition = 530.f;
        const std::string boardTexturePath = "assets/textures/board.png";
        sf::Texture boardTexture;
        sf::Sprite boardSprite;

        // Randomization
        std::default_random_engine randomEngine;

        // Private helper methods
        void initialize();
        void initializeBoardImage();

        void createBoard();
        float getCellWidthInBoard() const;
        float getCellHeightInBoard() const;
        void deleteBoard();

        void populateBoard();
        void populateMines();
        int countMinesAround(sf::Vector2i cell_position);
        void populateCells();

    public:
        Board();
        ~Board();

        // Game flow methods
        void render(sf::RenderWindow& window);

        bool isValidCellPosition(sf::Vector2i cell_position);
    };
}