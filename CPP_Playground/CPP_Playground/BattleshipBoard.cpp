#include "BattleshipBoard.h"

namespace BattleshipGame
{
	BattleshipGame::BattleshipBoard::BattleshipBoard()
	{
		rows = 0;
		columns = 0;
	}

	BattleshipGame::BattleshipBoard::BattleshipBoard(int _rows, int _colums)
	{
		rows = _rows;
		columns = _colums;
	}

	int BattleshipGame::BattleshipBoard::MaxCellsInBoard()
	{
		return rows * columns;
	}

	vector<Battleship*> BattleshipBoard::GenerateShips(int count, int maxSize)
	{
		vector<Battleship*> ships;

		for (int i = 0; i < count; i++)
		{
			Battleship* ship;
			do
			{
				int randSize = rand() % maxSize;
				Coordinate randLocation = GenerateRandomCoordinate();
				Direction randDirection = (Direction)(rand() % 4 + 0);

				ship = new Battleship(randSize, randLocation, randDirection, i);
			} while (!IsValidShipLocation(*ship));

			ships.push_back(ship);

			for (Coordinate coord : ship->GetCellsOccupiedByShip())
			{
				occupiedCells.push_back(coord);
			}			
		}
		
		return ships;
	}

	Coordinate BattleshipBoard::GenerateRandomCoordinate()
	{
		int x = rand() % this->rows + 0;
		int y = rand() % this->columns + 0;

		return Coordinate(x, y);
	}

	bool BattleshipBoard::IsValidShipLocation(Battleship ship)
	{
		for (Coordinate coord : ship.GetCellsOccupiedByShip())
		{
			if (!IsCoordinateOnBoard(coord))
			{
				return false; 
			}

			//Does it collide with other ships
			bool alreadyOccupied = (std::find(occupiedCells.begin(), occupiedCells.end(), coord) != occupiedCells.end());

			if (alreadyOccupied)
			{
				return false;
			}
		}

		return true;
	}

	bool BattleshipBoard::IsCoordinateOnBoard(Coordinate coord)
	{
		if (coord.x >= this->rows)
		{
			return false;
		}
		else if (coord.y >= this->columns)
		{
			return false;
		}
		else if (coord.x < 0)
		{
			return false;
		}
		else if (coord.y < 0)
		{
			return false;
		}
		return true;
	}
}