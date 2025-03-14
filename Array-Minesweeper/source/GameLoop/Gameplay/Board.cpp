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
		cell = new Cell(83, 83, sf::Vector2i(0, 0));
	}

	void Board::render(sf::RenderWindow& window)
	{
		window.draw(boardSprite);
		cell->render(window);
	}
}