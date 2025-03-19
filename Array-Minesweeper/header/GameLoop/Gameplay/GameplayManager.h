#pragma once
#include <SFML/Graphics.hpp>
#include"../../header/GameLoop/Gameplay/Board.h"
#include"../../header/Event/EventPollingManager.h"
#include"../../header/UI/GameplayUI.h"

namespace Gameplay {
	

	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	using namespace UI;

	class GameplayManager {
	private:

		Board* board;
		GameplayUI* gameplay_ui;

		const float background_alpha = 85.0f;

		const float max_level_duration = 150.0f;
		//const float game_over_time = 11.0f;
		float remaining_time;

		sf::Texture background_texture;
		sf::Sprite background_sprite;
		std::string background_texture_path = "assets/textures/minesweeper_bg.png";


		void initialize();
		void initializeVariables();
		void initializeBackgroundImage();

		GameResult game_result;

		bool hasGameEnded();

		void updateRemainingTime();
		void processTimeOver();

		void handleGameplay(Event::EventPollingManager& eventManager);

		void gameWon();
		void gameLost();

		int getRemainingMinesCount() const;

	public:

		GameplayManager();
		~GameplayManager();

		void update(Event::EventPollingManager& event_manager);

		void render(sf::RenderWindow& window);

		void setGameResult(GameResult game_result);

		void checkGameWin();
		void processGameResult();
	};
}