#pragma once
#include <SFML/Graphics.hpp>
#include<random>
#include "../../header/GameLoop/Gameplay/Cell.h"

namespace Gameplay {

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

        void initialize();
        void initializeBoardImage();
        void initializeVariables();

        void createBoard();

        float getCellWidthInBoard() const;
        float getCellHeightInBoard() const;

        void populateBoard();
        void populateMines();
        void populateCell();

        int countMinesAround(sf::Vector2i cell_postion);
        bool isvalidCellPosition(sf::Vector2i cell_position);

    public:
        Board();

        void update(Event::EventPollingManager& event_manager);

        void render(sf::RenderWindow& window);

        void onCellButtonClicked(sf::Vector2i cell_position, MouseButtonType mouse_button_type);
	};
}