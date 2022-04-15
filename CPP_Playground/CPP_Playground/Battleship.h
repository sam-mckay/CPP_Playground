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
		int id;
		int size;
		Direction direction;
		Coordinate location;
		bool destroyed = false;

		Battleship();
		Battleship(int size, Coordinate location, Direction direction);
		Battleship(int size, Coordinate location, Direction direction, int id);


		bool CheckIfHit(Coordinate targetCell);
		bool CheckIfDestroyed();
		int CheckHitCount();
		vector<Coordinate> GetCellsOccupiedByShip();
		Coordinate NextCellInDirection(Coordinate currentCell);
	};
}