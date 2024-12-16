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
        PopulateBoard();
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

    void Board::PopulateBoard()
    {
        PopulateMines();
        PopulateCells();
    }

    void Board::PopulateMines()
    {
        std::uniform_int_distribution<int> x_dist(0, numberOfColumns - 1);
        std::uniform_int_distribution<int> y_dist(0, numberOfRows - 1);

        int mines_placed = 0;
        while (mines_placed < minesCount)
        {
            int x = x_dist(randomEngine);
            int y = y_dist(randomEngine);

            board[x][y]->SetCellType(CellType::MINE);
            ++mines_placed;
        }
    }

    void Board::PopulateCells()
    {
        for (int row = 0; row < numberOfRows; ++row)
        {
            for (int col = 0; col < numberOfColumns; ++col)
            {
                if (board[row][col]->GetCellType() != CellType::MINE)
                {
                    int mines_around = CountMinesAround(sf::Vector2i(row, col));
                    board[row][col]->SetCellType(static_cast<CellType>(mines_around));
                }
            }
        }
    }

    int Board::CountMinesAround(sf::Vector2i cell_position)
    {
        int mines_around = 0;

        for (int a = -1; a <= 1; ++a)
        {
            for (int b = -1; b <= 1; ++b)
            {
                if ((a == 0 && b == 0) || !IsValidCellPosition(sf::Vector2i(cell_position.x + a, cell_position.y + b)))
                    continue;

                if (board[cell_position.x + a][cell_position.y + b]->GetCellType() == CellType::MINE)
                    mines_around++;
            }
        }

        return mines_around;
    }

    bool Board::IsValidCellPosition(sf::Vector2i cell_position) {
        return (cell_position.x >= 0 && cell_position.y >= 0 &&
            cell_position.x < numberOfColumns && cell_position.y < numberOfRows);
    }

    void Board::CreateBoard()
    {
        float cell_width = GetCellWidthInBoard();
        float cell_height = GetCellHeightInBoard();
        for (int row = 0; row < numberOfRows; ++row)
        {
            for (int col = 0; col < numberOfColumns; ++col)
            {
                board[row][col] = new Cell(cell_width, cell_height, sf::Vector2i(row, col));
            }
        }
    }

    void Board::Render(sf::RenderWindow& window)
    {
        window.draw(boardSprite);
        for (int row = 0; row < numberOfRows; ++row)
        {
            for (int col = 0; col < numberOfColumns; ++col)
            {
                board[row][col]->Render(window);
            }
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
