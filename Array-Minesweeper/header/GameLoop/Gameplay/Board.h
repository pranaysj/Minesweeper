#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Sound/SoundManager.h"

namespace Gameplay
{
    class GameplayManager;
    enum class BoardState
    {
        FIRST_CELL,
        PLAYING,
        COMPLETED,
    };

    class Board
    {
    private:

        // State and View Members
        BoardState boardState;
        Cell* board;
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
        std::random_device randomDevice;

        // Private helper methods
        void CreateBoard();
        void InitializeBoardImage();

    public:
        Board();


        // Game flow methods
        void Initialize();
        void Render(sf::RenderWindow& window);

        //Getters
        float GetCellWidthInBoard() const;
        float GetCellHeightInBoard() const;
    };
}
