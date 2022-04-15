#pragma once
#include "Battleship.h"
#include "Direction.h"
#include <list>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

namespace BattleshipGame
{
	class BattleshipBoard
	{
	private:
		list<Coordinate> occupiedCells;

	public:
		int rows;
		int columns;
		

		BattleshipBoard();
		BattleshipBoard(int _rows, int _colums);

		int MaxCellsInBoard();
		vector<Battleship*> GenerateShips(int count, int maxSize);
		Coordinate GenerateRandomCoordinate();
		bool IsValidShipLocation(Battleship ship);
		bool IsCoordinateOnBoard(Coordinate target);
	};
}