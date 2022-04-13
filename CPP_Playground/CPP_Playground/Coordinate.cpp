#include "Coordinate.h"

namespace BattleshipGame
{
	Coordinate::Coordinate()
	{
		x = 0;
		y = 0;
	}

	Coordinate::Coordinate(int x, int y)
	{
		Coordinate::x = x;
		Coordinate::y = y;
	}

	bool Coordinate::operator==(const Coordinate &otherCoord)
	{
		if (x == otherCoord.x && y == otherCoord.y)
		{
			return true;
		}
		else return false;
	}

	bool Coordinate::operator!=(const Coordinate &otherCoord)
	{
		if (x != otherCoord.x && y != otherCoord.y)
		{
			return true;
		}
		else return false;
	}
}