#pragma once
#include <SFML/Graphics.hpp>

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

			void initialize(const std::string &texture_path, const  sf::Vector2f &postion, float width, float height);

		public:
			Button(const std::string &texture_path, const  sf::Vector2f &postion, float width, float height);

			void render(sf::RenderWindow& window);

			void setTexturesRect(const sf::IntRect& rect);
		};
	}
}