#include <iostream>
#include "../../header/GameLoop/Gameplay/GameplayManager.h"
#include "../../../header/Time/TimeManager.h"

namespace Gameplay
{
    GameplayManager::GameplayManager() { initialize(); }

    void GameplayManager::initialize()
    {
        initializeBackgroundImage();
        initializeVariables();
    }

    void GameplayManager::initializeBackgroundImage()
    {
        if (!background_texture.loadFromFile(background_texture_path))
        {
            std::cerr << "Failed to load background texture!" << std::endl;
            return;
        }

        background_sprite.setTexture(background_texture);
        background_sprite.setColor(sf::Color(255, 255, 255, background_alpha));
    }

    void GameplayManager::initializeVariables()
    {
        board = new Board(this);

        remaining_time = max_level_duration;
        game_result = GameResult::NONE;
    }

    void GameplayManager::update(EventPollingManager* eventManager, sf::RenderWindow* window)
    {
        if (!hasGameEnded())
            handleGameplay(eventManager, window);
        else if(BoardState::COMPLETED != board->getBoardState())
            processGameResult();
    }

    void GameplayManager::handleGameplay(EventPollingManager* eventManager, sf::RenderWindow* window)
    {
        updateRemainingTime();
        board->update(*eventManager, *window);
        checkGameWin();
    }

    void GameplayManager::updateRemainingTime()
    {
        remaining_time -= Time::TimeManager::getDeltaTime();
        processTimeOver();
    }

    void GameplayManager::processTimeOver()
    {
        if (remaining_time <= 0)
        {
            remaining_time = 0;
            game_result = GameResult::LOST;
            board->setBoardState(BoardState::COMPLETED);
        }
    }

    void GameplayManager::checkGameWin()
    {
        if (board->areAllCellsOpen())
        {
            game_result = GameResult::WON;
        }
    }

    void GameplayManager::processGameResult()
    {
        switch (game_result)
        {
        case GameResult::WON:
            gameWon();
            break;
        case GameResult::LOST:
            gameLost();
            break;
        default:
            break;
        }
    }

    void GameplayManager::gameWon()
    {
        board->setBoardState(BoardState::COMPLETED);
        Sound::SoundManager::PlaySound(Sound::SoundType::GAME_WON);
        board->flagAllMines();
        // game_result = GameResult::NONE;
    }

    void GameplayManager::gameLost()
    {
        board->setBoardState(BoardState::COMPLETED);
        game_result = GameResult::NONE;
    }

    void GameplayManager::render(sf::RenderWindow& window)
    {
        window.draw(background_sprite);
        board->render(window);
    }

    bool GameplayManager::hasGameEnded() { return game_result != GameResult::NONE || board->getBoardState() == BoardState::COMPLETED;
}

    int GameplayManager::getMinesCount() const { return board->getMinesCount(); }

    void GameplayManager::setGameResult(GameResult gameResult) { this->game_result = gameResult; }
}