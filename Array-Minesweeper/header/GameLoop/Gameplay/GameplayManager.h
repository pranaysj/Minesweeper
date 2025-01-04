#pragma once
#include "../../header/GameLoop/Gameplay/Board.h"
#include "../../header/Event/EventPollingManager.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    using namespace UIElements;
    using namespace Event;

    enum class GameResult
    {
        NONE,
        WON,
        LOST
    };

    class GameplayManager
    {
    private:
        const float background_alpha = 85.f;
        sf::Texture background_texture;
        sf::Sprite background_sprite;
        std::string background_texture_path = "assets/textures/minesweeper_bg.png";

        Board* board;


        void initialize();
        void initializeBackgroundImage();
        void initializeVariables();


    public:
        GameplayManager();
        ~GameplayManager() = default;

        void render(sf::RenderWindow& window);
    };
}