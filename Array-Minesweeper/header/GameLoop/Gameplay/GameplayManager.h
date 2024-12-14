#pragma once
#include "../../header/GameLoop/Gameplay/Board.h"
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Time/TimeManager.h"
#include "../../header/Sound/SoundManager.h"
#include <SFML/Graphics.hpp>



namespace Gameplay
{
    enum class GameResult
    {
        NONE,
        WON,
        LOST
    };

    class GameplayManager
    {
    private:
        const float backgroundAlpha = 85.f;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        std::string backgroundTexturePath = "assets/textures/minesweeper_bg.png";

        Board *board;

    public:
        GameplayManager();
        ~GameplayManager() = default;

        void Initialize();
        void InitializeBackgroundImage();

        void Update(Event::EventPollingManager& eventManager, sf::RenderWindow& window);
        void Render(sf::RenderWindow& window);
    };
}
