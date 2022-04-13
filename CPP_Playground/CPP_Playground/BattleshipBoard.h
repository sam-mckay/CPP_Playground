#pragma once

namespace BattleshipGame
{
	class BattleshipBoard
	{
	public:
		int rows;
		int columns;
		

		BattleshipBoard();
		BattleshipBoard(int _rows, int _colums);

		int MaxCellsInBoard();
	};
}