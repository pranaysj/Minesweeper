#include "../../header/GameLoop/Gameplay/GameplayManager.h"
#include <iostream>

namespace Gameplay
{
    GameplayManager::GameplayManager()
    {
        Initialize();
    }

    void GameplayManager::Initialize()
    {
        InitializeBackgroundImage();
        board = new Board();
    }

    void GameplayManager::InitializeBackgroundImage()
    {
        if (!backgroundTexture.loadFromFile(backgroundTexturePath))
        {
            std::cerr << "Failed to load background texture!" << std::endl;
            return;
        }
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setColor(sf::Color(255, 255, 255, backgroundAlpha));
    }

    void GameplayManager::Render(sf::RenderWindow& window)
    {
        window.draw(backgroundSprite);
        board->Render(window);
    }
}
