#pragma once
#include <SFML/Graphics.hpp>
#include"../../header/GameLoop/Gameplay/Board.h"

namespace Gameplay {
	
	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayManager {
	private:

		Board* board;

		const float background_alpha = 85.0f;

		sf::Texture background_texture;
		sf::Sprite background_sprite;
		std::string background_texture_path = "assets/textures/minesweeper_bg.png";


		void initialize();
		void initializeVariables();
		void initializeBackgroundImage();

		GameResult game_result;

		bool hasGameEnded();

	public:

		GameplayManager();
		~GameplayManager();

		void update(Event::EventPollingManager& event_manager);

		void render(sf::RenderWindow& window);

		void setGameResult(GameResult game_result);
	};
}