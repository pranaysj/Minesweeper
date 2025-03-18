#include"../../header/GameLoop/Gameplay/Board.h"
#include <iostream>

namespace Gameplay {
	Board::Board()
	{
		initialize();
	}

	void Board::update(Event::EventPollingManager& event_manager)
	{
		for (int row = 0; row < numberOfRows; ++row)
		{
			for (int col = 0; col < numberOfColumns; ++col)
			{
				cell[row][col]->update(event_manager);
			}
		}
	}

	void Board::initialize()
	{
		initializeBoardImage();
		initializeVariables();
		createBoard();
		populateBoard();
	}

	void Board::initializeBoardImage()
	{
		if (!boardTexture.loadFromFile(boardTexturePath)) {
			std::cerr << "Failed to load board texture" << std::endl;
		}

		boardSprite.setTexture(boardTexture);
		boardSprite.setPosition(boardPosition, 0);
		boardSprite.setScale(
			boardWidth / boardTexture.getSize().x,
			boardHeight / boardTexture.getSize().y);
	}

	void Board::initializeVariables()
	{
		randomEngine.seed(randomDevice());
	}

	void Board::createBoard()
	{
		float cellWidth = getCellWidthInBoard();
		float cellHeight = getCellHeightInBoard();

		for (int row = 0; row < numberOfRows; ++row)
		{
			for (int col = 0; col < numberOfColumns; ++col)
			{
				cell[row][col] = new Cell(cellWidth, cellHeight, sf::Vector2i(row, col), this);
			}
		}
	}

	float Board::getCellWidthInBoard() const
	{
		return (boardWidth - horizontalCellPadding) / numberOfColumns;
	}

	float Board::getCellHeightInBoard() const
	{
		return (boardHeight - verticalCellPadding) / numberOfRows;
	}

	void Board::populateBoard()
	{
		populateMines();
		populateCell();
	}

	void Board::populateMines()
	{
		std::uniform_int_distribution<int> x_dist(0, numberOfColumns - 1);
		std::uniform_int_distribution<int> y_dist(0, numberOfRows - 1);
		int mines_placed = 0;

		while (mines_placed < minesCount)
		{
			int x = x_dist(randomEngine);
			int y = y_dist(randomEngine);

			if (cell[x][y]->getCellType() != CellType::MINE) {
				cell[x][y]->setCellType(CellType::MINE);
				++mines_placed;
			}
		}
	}

	void Board::populateCell()
	{
		for (int row = 0; row < numberOfRows; ++row) {

			for (int col = 0; col < numberOfColumns; ++col)
			{
				if (cell[row][col]->getCellType() != CellType::MINE)
				{
					int mines_around = countMinesAround(sf::Vector2i(row, col));
					cell[row][col]->setCellType(static_cast<CellType>(mines_around));
				}
			}
		}
	}

	int Board::countMinesAround(sf::Vector2i cell_postion)
	{
		int mines_around = 0;

		for (int a = -1; a <= 1; a++) //Check for ++a
		{
			for (int b = -1; b <= 1; b++)
			{

				if (a == 0 && b == 0 || 
					/*This ensures that if the neighboring cell position is out of bounds,
					we skip that iteration to prevent accessing an invalid memory location.*/
					!isvalidCellPosition(sf::Vector2i(cell_postion.x + a, cell_postion.y + b)))
					
					/*If either of the two conditions is true,
					the continue statement skips the rest of the loop body and moves to the next iteration.*/
					continue;

				if (cell[cell_postion.x + a][cell_postion.y + b]->getCellType() == CellType::MINE) {
					mines_around++;
				}
			}
		}

		return mines_around;
	}

	bool Board::isvalidCellPosition(sf::Vector2i cell_position)
	{
		return (cell_position.x >= 0 && cell_position.y > 0 && cell_position.x < numberOfColumns && cell_position.y < numberOfRows);
	}

	void Board::render(sf::RenderWindow& window)
	{
		window.draw(boardSprite);

		for (int row = 0; row < numberOfRows; ++row)
		{
			for (int col = 0; col < numberOfColumns; ++col)
			{
				cell[row][col]->render(window);
			}
		}
	}
	void Board::onCellButtonClicked(sf::Vector2i cell_position, MouseButtonType mouse_button_type)
	{
		if (mouse_button_type == MouseButtonType::LEFT_MOUSE_BUTTON) {

		}
		else if (mouse_button_type == MouseButtonType::RIGHT_MOUSE_BUTTON) {

		}
	}
}