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
}