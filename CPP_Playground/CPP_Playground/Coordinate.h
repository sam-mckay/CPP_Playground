#pragma once

namespace BattleshipGame
{
	class Coordinate
	{
	public:
		int x;
		int y;
		Coordinate();
		Coordinate(int x, int y);

		bool operator ==(const Coordinate &otherCoord);
		bool operator !=(const Coordinate &otherCoord);
	};
}
