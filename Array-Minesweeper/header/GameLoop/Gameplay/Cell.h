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

    class Board;
	class Cell {

	private:

        Board* board;

        CellState current_cell_state;
        CellType cell_type;
		sf::Vector2i position;

        const int tile_size = 128;
		const int slice_count = 12;

		const std::string cell_texture_path = "assets/textures/cells.jpeg";

        const float cell_top_offset = 274.f;
        const float cell_left_offset = 583.f;

		Button* cell_button;
        void registeCellButtonCallback();
        void cellButtonCallback(MouseButtonType button_type);

		void initialize(float width, float height, sf::Vector2i position, Board* board);

        sf::Vector2f getCellScreenPosition(float width, float height) const;

	public:

		Cell(float width, float height, sf::Vector2i position, Board* board);
		~Cell() = default;

        void update(Event::EventPollingManager& event_manager);

		void render(sf::RenderWindow& window);

        void setCellState(CellState state);
        CellState getCellState();

        void setCellType(CellType type);
        CellType getCellType();

        void setCellTexture();

        sf::Vector2i getCellPosition();

        bool canOpenCell();
        void open();

        void toggleFlag();

        void reset();

	};
}