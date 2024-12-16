#include "../../header/GameLoop/Gameplay/Board.h"
#include "../../header/GameLoop/Gameplay/GameplayManager.h"
#include <iostream>

namespace Gameplay
{
    Board::Board()
    {
        Initialize();
    }

    void Board::Initialize()
    {
        InitializeBoardImage();
        CreateBoard();
    }

    void Board::InitializeBoardImage()
    {
        if (!boardTexture.loadFromFile(boardTexturePath))
        {
            std::cerr << "Failed to load board texture!" << std::endl;
            return;
        }
        boardSprite.setTexture(boardTexture);
        boardSprite.setPosition(boardPosition, 0);
        boardSprite.setScale(boardWidth / boardTexture.getSize().x, boardHeight / boardTexture.getSize().y);
    }

    void Board::CreateBoard()
    {
        float cell_width = GetCellWidthInBoard();
        float cell_height = GetCellHeightInBoard();
        for (int col = 0; col < numberOfColumns; ++col) {
        board[col] = new Cell(cell_width, cell_height, sf::Vector2i(col, 0));
        }
    }

    void Board::Render(sf::RenderWindow& window)
    {
        window.draw(boardSprite);
        for (int col = 0; col < numberOfColumns; ++col) {
            board[col]->Render(window);
        }
    }

    float Board::GetCellWidthInBoard() const
    {
        return (boardWidth - horizontalCellPadding) / numberOfColumns;
    }

    float Board::GetCellHeightInBoard() const
    {
        return (boardHeight - verticalCellPadding) / numberOfColumns;
    }
}
