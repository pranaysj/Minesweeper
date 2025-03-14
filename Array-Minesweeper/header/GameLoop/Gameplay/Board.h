#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/GameLoop/Gameplay/Cell.h"

namespace Gameplay {

	class Board {
    private:

        const float boardWidth = 866.f;
        const float boardHeight = 1080.f;
        const float boardPosition = 530.f;

        const std::string boardTexturePath = "assets/textures/board.png";
        sf::Texture boardTexture;
        sf::Sprite boardSprite;

        Cell* cell;

        void initialize();
        void initializeBoardImage();

        void createBoard();

    public:
        Board();

        void render(sf::RenderWindow& window);
	};
}