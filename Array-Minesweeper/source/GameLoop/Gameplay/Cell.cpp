#include"../../header/GameLoop/Gameplay/Cell.h"
#include<iostream>

namespace Gameplay {

	Cell::Cell(float width, float height, sf::Vector2i position)
	{
		initialize(width, height, position);
	}

	void Cell::initialize(float width, float height, sf::Vector2i position)
	{
		//this->position = position;
		//sf::Vector2f float_position(static_cast<float>(position.x), static_cast<float>(position.y));
		
		current_cell_state = CellState::HIDDEN;
		sf::Vector2f cellScreenPosition = getCellScreenPosition();
		cell_button = new Button(cell_texture_path, cellScreenPosition, width * slice_count , height);
	}

	sf::Vector2f Cell::getCellScreenPosition() const
	{
		float xScreenPosition = cell_left_offset;
		float yScreenPosition = cell_top_offset;
		return sf::Vector2f(xScreenPosition, yScreenPosition);
	}

	void Cell::setCellState(CellState state)
	{
		current_cell_state = state;
	}

	CellState Cell::getCellState()
	{
		return current_cell_state;
	}

	void Cell::setCellType(CellType type)
	{
		cell_type = type;
	}

	CellType Cell::getCellType()
	{
		return cell_type;
	}

	void Cell::setCellTexture()
	{
		int index = static_cast<int>(cell_type);

		switch (current_cell_state)
		{	
		case Gameplay::CellState::HIDDEN:
			cell_button->setTexturesRect(sf::IntRect(128, 0, tile_size, tile_size));
			break;
		case Gameplay::CellState::OPEN:
			cell_button->setTexturesRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
			break;
		case Gameplay::CellState::FLAGGED:
			cell_button->setTexturesRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
			break;
		}
	}

	void Cell::render(sf::RenderWindow& window)
	{
		setCellTexture();

		if (cell_button)
			cell_button->render(window);
	}
}