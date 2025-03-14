#pragma once
#include<SFML/Graphics.hpp>
#include"../../header/UI/UIElements/Button.h"

namespace Gameplay {

	using namespace UI::UIElements;

	class Cell {

	private:

		sf::Vector2i position;

		const int slice_count = 12;

		const std::string cell_texture_path = "assets/textures/cells.jpeg";

		Button* cell_button;

		void initialize(float width, float height, sf::Vector2i position);

	public:

		Cell(float width, float height, sf::Vector2i position);
		~Cell() = default;

		void render(sf::RenderWindow& window);
	};
}