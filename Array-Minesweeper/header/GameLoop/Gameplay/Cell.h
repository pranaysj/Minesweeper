#pragma once
#include<SFML/Graphics.hpp>
#include"../../header/UI/UIElements/Button.h"

namespace Gameplay {

	using namespace UI::UIElements;

    enum class CellState
    {
        HIDDEN,
            OPEN,
            FLAGGED,
    };

    enum class CellType
    {
        EMPTY,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        MINE,
    };

	class Cell {

	private:

		sf::Vector2i position;

        const int tile_size = 128;
		const int slice_count = 12;

		const std::string cell_texture_path = "assets/textures/cells.jpeg";

		Button* cell_button;

        CellState current_cell_state;
        CellType cell_type;

		void initialize(float width, float height, sf::Vector2i position);

	public:

		Cell(float width, float height, sf::Vector2i position);
		~Cell() = default;

		void render(sf::RenderWindow& window);

        void setCellState(CellState state);
        CellState getCellState();

        void setCellType(CellType type);
        CellType getCellType();

        void setCellTexture();
	};
}