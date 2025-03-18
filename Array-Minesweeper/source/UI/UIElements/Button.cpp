#include<iostream>
#include"../../header/UI/UIElements/Button.h"

namespace UI {
	namespace UIElements {

		Button::Button(const std::string &texture_path, const sf::Vector2f &position, float width, float height)
		{
			initialize(texture_path, position, width, height);
		}

		void Button::update(Event::EventPollingManager& event_manager)
		{
			handleButtonInteraction(event_manager);
		}

		void Button::initialize(const std::string &texture_path, const sf::Vector2f &position, float width, float height)
		{
			if (!button_texture.loadFromFile(texture_path)) {
				std::cerr << "Failed to load button texture: " << texture_path << std::endl;
				return;
			}

			button_sprite.setTexture(button_texture);
			button_sprite.setPosition(position);
			button_sprite.setScale(width / button_texture.getSize().x, height / button_texture.getSize().y);
		}

		void Button::handleButtonInteraction(Event::EventPollingManager& event_manager)
		{
			if (event_manager.pressedLeftMouseButton() && isMouseOnSprite(event_manager))
			{
				callback_function(MouseButtonType::LEFT_MOUSE_BUTTON);
			}
			if (event_manager.pressedRightMouseButton() && isMouseOnSprite(event_manager))
			{
				callback_function(MouseButtonType::RIGHT_MOUSE_BUTTON);
			}
		}

		bool Button::isMouseOnSprite(Event::EventPollingManager& event_manager)
		{
			sf::Vector2i mouse_position = event_manager.getMousePosition();
			return button_sprite.getGlobalBounds().contains(static_cast<float>(mouse_position.x), static_cast<float>(mouse_position.y));
		}

		void Button::render(sf::RenderWindow& window)
		{
			window.draw(button_sprite);
		}

		void Button::setTexturesRect(const sf::IntRect& rect)
		{
			button_sprite.setTextureRect(rect);
		}
		void Button::registerCallbackFunction(CallbackFunction button_callback)
		{
			callback_function = button_callback;
		}
	}
}