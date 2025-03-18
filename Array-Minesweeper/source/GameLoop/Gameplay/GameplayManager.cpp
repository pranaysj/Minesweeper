#include <iostream>
#include "../../header/GameLoop/Gameplay/GameplayManager.h"
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
			handleGameplay(event_manager);
	}

	void GameplayManager::handleGameplay(Event::EventPollingManager& event_manager)
	{
		updateRemainingTime();
		board->update(event_manager);
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
}
