#include<iostream>
#include"../../header/GameLoop/Gameplay/Cell.h"
#include"../../header/GameLoop/Gameplay/Board.h"

namespace Gameplay {

	Cell::Cell(float width, float height, sf::Vector2i position, Board* board)
	{
		initialize(width, height, position, board);
	}

	void Cell::initialize(float width, float height, sf::Vector2i position, Board* board)
	{
		this->position = position;
		this->board = board;
		current_cell_state = CellState::HIDDEN;
		sf::Vector2f cellScreenPosition = getCellScreenPosition(width, height);
		cell_button = new Button(cell_texture_path, cellScreenPosition, width * slice_count , height);

		registeCellButtonCallback();
	}

	void Cell::registeCellButtonCallback()
	{
		cell_button->registerCallbackFunction([this](MouseButtonType button_type) {
			cellButtonCallback(button_type);
		});
	}

	void Cell::cellButtonCallback(MouseButtonType button_type)
	{
		board->onCellButtonClicked(getCellPosition(), button_type);
	}

	sf::Vector2f Cell::getCellScreenPosition(float width, float height) const
	{
		float xScreenPosition = cell_left_offset + position.x * width;
		float yScreenPosition = cell_top_offset + position.y * height;
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
			cell_button->setTexturesRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
			break;
		case Gameplay::CellState::OPEN:
			cell_button->setTexturesRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
			break;
		case Gameplay::CellState::FLAGGED:
			cell_button->setTexturesRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
			break;
		}
	}

	sf::Vector2i Cell::getCellPosition()
	{
		return position;
	}

	void Cell::update(Event::EventPollingManager& event_manager)
	{
		cell_button->update(event_manager);
	}

	void Cell::render(sf::RenderWindow& window)
	{
		setCellTexture();

		if (cell_button)
			cell_button->render(window);
	}
}