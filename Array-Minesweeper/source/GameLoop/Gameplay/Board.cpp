#include"../../header/GameLoop/Gameplay/Board.h"
#include <iostream>

namespace Gameplay {
	Board::Board()
	{
		initialize();
	}

	void Board::initialize()
	{
		initializeBoardImage();
		createBoard();
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

	void Board::createBoard()
	{
		float cellWidth = getCellWidthInBoard();
		float cellHeight = getCellHeightInBoard();

		for (int row = 0; row < numberOfRows; ++row)
		{
			for (int col = 0; col < numberOfColumns; ++col)
			{
				cell[row][col] = new Cell(cellWidth, cellHeight, sf::Vector2i(row, col));
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
}