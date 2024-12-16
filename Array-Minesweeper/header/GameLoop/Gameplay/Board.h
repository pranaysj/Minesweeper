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

        Cell* board;
        
        const float horizontalCellOffset = 115.f;
        const float verticalCellOffset = 329.f;

        // Board Rendering
        const float boardWidth = 866.f;
        const float boardHeight = 1080.f;

        const float boardPosition = 530.f;

        const std::string boardTexturePath = "assets/textures/board.png";

        sf::Texture boardTexture;
        sf::Sprite boardSprite;

        // Private helper methods
        void CreateBoard();
        void InitializeBoardImage();
        void Initialize();

    public:
        Board();

        // Game flow methods
        void Render(sf::RenderWindow& window);

        //Getters
        float GetCellWidthInBoard() const;
        float GetCellHeightInBoard() const;
    };
}
