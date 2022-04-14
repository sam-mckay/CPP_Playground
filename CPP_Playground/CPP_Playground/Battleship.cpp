#include "Battleship.h"
#include "Direction.h"
#include <list>

namespace BattleshipGame
{
    Battleship::Battleship()
    {
        Battleship::size = 0;
        Battleship::location = Coordinate(0,0);
        Battleship::direction = Direction::North;
    }

    Battleship::Battleship(int size, Coordinate location, Direction direction)
    {
        Battleship::size = size;
        Battleship::location = location;
        Battleship::direction = direction;
    }

    bool Battleship::CheckIfHit(Coordinate targetCell)
    {


        return false;
    }

    vector<Coordinate> Battleship::GetCellsOccupiedByShip()
    {
        vector<Coordinate> occupiedCells;

        occupiedCells.push_back(location);

        for (int i = 0; i < size; i++)
        {
            Coordinate nextCell = Coordinate();
            nextCell = NextCellInDirection(occupiedCells.back());
            occupiedCells.push_back(nextCell);
        }

        return occupiedCells;
    }

    Coordinate Battleship::NextCellInDirection(Coordinate currentCell)
    {
        switch (direction)
        {
            case Direction::North:
            {
                Coordinate nextCell= { currentCell.x , currentCell.y + 1 };
                return nextCell;
            }
            case Direction::East:
            {
                Coordinate nextCell = { currentCell.x + 1, currentCell.y };
                return nextCell;
            }
            case Direction::South:
            {
                Coordinate nextCell= { currentCell.x , currentCell.y - 1 };
                return nextCell;
            }
            case Direction::West:
            {
                Coordinate nextCell = { currentCell.x - 1, currentCell.y };
                return nextCell;
            }
            default:
                break;
        }

        Coordinate nextCell = { 0,0 };
        return nextCell;
    }

}