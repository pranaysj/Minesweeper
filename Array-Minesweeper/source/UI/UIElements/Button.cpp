#include"../../header/UI/UIElements/Button.h"
#include<iostream>

namespace UI {
	namespace UIElements {

		Button::Button(const std::string &texture_path, const sf::Vector2f &position, float width, float height)
		{
			initialize(texture_path, position, width, height);
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

		void Button::render(sf::RenderWindow& window)
		{
			window.draw(button_sprite);
		}

		void Button::setTextureRect(const sf::IntRect& rect)
		{
			button_sprite.setTextureRect(rect);
		}
	}
}