#include <iostream>
#include "../../header/GameLoop/Gameplay/GameplayManager.h"
#include "../../header/Sound/SoundManager.h"
#include "../../header/Time/TimeManager.h"

namespace Gameplay {
	GameplayManager::GameplayManager()
	{
		initialize();
	}

	void GameplayManager::initialize()
	{
		initializeVariables();
		initializeBackgroundImage();
	}

	void GameplayManager::initializeVariables()
	{
		board = new Board(this);
		remaining_time = max_level_duration;
	}

	void GameplayManager::initializeBackgroundImage()
	{
		if (!background_texture.loadFromFile(background_texture_path)) {
			std::cerr << "Failed to load background texture" << std::endl;
		}

		background_sprite.setTexture(background_texture);
		background_sprite.setColor(sf::Color(255, 255, 255, background_alpha));
	}

	bool GameplayManager::hasGameEnded()
	{
		return game_result != GameResult::NONE;
	}

	void GameplayManager::updateRemainingTime()
	{
		remaining_time -= Time::TimeManager::getDeltaTime();
		processTimeOver();
	}

	void GameplayManager::processTimeOver()
	{
		if (remaining_time < 0) {
			remaining_time = 0;
			setGameResult(GameResult::LOST);
		}
	}

	GameplayManager::~GameplayManager()
	{
		delete(board);
	}

	void GameplayManager::update(Event::EventPollingManager& event_manager)
	{
		if (!hasGameEnded())
		{
			handleGameplay(event_manager);
		}
		else if (board->getBoardState() == BoardState::COMPLETED) 
		{
			processGameResult();
		}
	}

	void GameplayManager::handleGameplay(Event::EventPollingManager& event_manager)
	{
		updateRemainingTime();
		board->update(event_manager);
		checkGameWin();
	}

	void GameplayManager::gameWon()
	{
		Sound::SoundManager::PlaySound(Sound::SoundType::GAME_WON);  // Play victory sound
		board->flagAllMine(); // Show all mines
		board->setBoardState(BoardState::COMPLETED);  // Stop the game
	}

	void GameplayManager::gameLost()
	{
		Sound::SoundManager::PlaySound(Sound::SoundType::EXPLOSION);  // Boom!
		board->setBoardState(BoardState::COMPLETED);  // Game over
		board->revealAllMines();  // Show where the mines were
	}

	void GameplayManager::render(sf::RenderWindow& window)
	{
		window.draw(background_sprite);
		board->render(window);
	}

	void GameplayManager::setGameResult(GameResult game_result)
	{
		this->game_result = game_result;
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
		switch (game_result) {
		case GameResult::WON:
			gameWon();    // Victory! 🎉
			break;
		case GameResult::LOST:
			gameLost();   // Game Over! 💥
			break;
		default:
			break;
		}
	}
}
