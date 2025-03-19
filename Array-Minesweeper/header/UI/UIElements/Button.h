#pragma once
#include <SFML/Graphics.hpp>
#include"../../header/Event/EventPollingManager.h"
#include <functional>

namespace UI {
	namespace UIElements {

		enum class MouseButtonType
		{
			LEFT_MOUSE_BUTTON,
			RIGHT_MOUSE_BUTTON
		};

		class Button {
		private:
			sf::Texture button_texture;
			sf::Sprite button_sprite;

			using CallbackFunction = std::function<void(MouseButtonType)>;
			CallbackFunction callback_function = nullptr;

			void initialize(const std::string &texture_path, const  sf::Vector2f &postion, float width, float height);

			bool isMouseOnSprite(Event::EventPollingManager& event_manager);


		public:
			Button(const std::string &texture_path, const  sf::Vector2f &postion, float width, float height);

			void update(Event::EventPollingManager& event_manager);

			void render(sf::RenderWindow& window);

			void handleButtonInteraction(Event::EventPollingManager& event_manager);
			
			void setTexturesRect(const sf::IntRect& rect);

			void registerCallbackFunction(CallbackFunction button_callback);
		};
	}
}