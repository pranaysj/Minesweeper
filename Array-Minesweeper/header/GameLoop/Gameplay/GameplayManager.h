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
        const float maxLevelDuration = 150.0f;
        const float gameOverTime = 11.0f;
        float remainingTime;

        const float backgroundAlpha = 85.f;

        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        std::string backgroundTexturePath = "assets/textures/minesweeper_bg.png";

        Board *board;
        GameResult gameResult = GameResult::NONE;

    public:
        GameplayManager();
        ~GameplayManager() = default;

        void Initialize();
        void InitializeBackgroundImage();
        void Render(sf::RenderWindow& window);
    };
}
