#include "../../header/GameLoop/Gameplay/Cell.h"
#include "../../header/GameLoop/Gameplay/Board.h"
#include <iostream>

namespace Gameplay
{
    Cell::Cell(float width, float height, sf::Vector2i position)
    {
        Initialize(width, height, position);
    }

    void Cell::Initialize(float width, float height, sf::Vector2i position)
    {
        this->position = position;
        currentCellState = CellState::HIDDEN;
        sf::Vector2f cellScreenPosition = GetCellScreenPosition(width, height);
        cellButton = new Button(cellTexturePath, cellScreenPosition, width * sliceCount, height);
    }

    sf::Vector2f Cell::GetCellScreenPosition(float width, float height) const
    {
        float xScreenPosition = cellLeftOffset + position.x * width;
        float yScreenPosition = cellTopOffset + position.y * height;
        return sf::Vector2f(xScreenPosition, yScreenPosition);
    }

    void Cell::SetCellTexture()
    {
        int index = static_cast<int>(cellType);

        switch (currentCellState)
        {
        case CellState::HIDDEN:
            cellButton->SetTextureRect(sf::IntRect(10 * tileSize, 0, tileSize, tileSize));
            break;
        case CellState::OPEN:
            cellButton->SetTextureRect(sf::IntRect(index * tileSize, 0, tileSize, tileSize));
            break;
        case CellState::FLAGGED:
            cellButton->SetTextureRect(sf::IntRect(11 * tileSize, 0, tileSize, tileSize));
            break;
        }
    }

    void Cell::Render(sf::RenderWindow& window)
    {
        SetCellTexture();
        if (cellButton) cellButton->Render(window);
    }

    CellType Cell::GetCellType()
    {
        return cellType;
    }

    void Cell::SetCellType(CellType type)
    {
        cellType = type;
    }
}
