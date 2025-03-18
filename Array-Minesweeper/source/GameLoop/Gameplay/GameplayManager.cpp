#include "../../header/GameLoop/Gameplay/GameplayManager.h"
#include <iostream>
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

	GameplayManager::~GameplayManager()
	{
		delete(board);
	}

	void GameplayManager::update(Event::EventPollingManager& event_manager)
	{
		if(!hasGameEnded())
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
