#pragma once
#include "Direction.h"
#include "Coordinate.h"
#include <vector>

using namespace std;

namespace BattleshipGame
{
	class Battleship
	{
	private: 
		vector<Coordinate> hitCells;
	public:
		int size;
		Direction direction;
		Coordinate location;
		bool destroyed = false;

		Battleship();
		Battleship(int size, Coordinate location, Direction direction);

		bool CheckIfHit(Coordinate targetCell);
		bool CheckIfDestroyed();
		vector<Coordinate> GetCellsOccupiedByShip();
		Coordinate NextCellInDirection(Coordinate currentCell);
	};
}