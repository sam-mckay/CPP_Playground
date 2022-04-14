#pragma once
#include "Direction.h"
#include "Coordinate.h"
#include <vector>

using namespace std;

namespace BattleshipGame
{
	class Battleship
	{
	public:
		int size;
		Direction direction;
		Coordinate location;
		bool destroyed = false;

		Battleship();
		Battleship(int size, Coordinate location, Direction direction);

		bool CheckIfHit(Coordinate targetCell);
		vector<Coordinate> GetCellsOccupiedByShip();
		Coordinate NextCellInDirection(Coordinate currentCell);
	};
}