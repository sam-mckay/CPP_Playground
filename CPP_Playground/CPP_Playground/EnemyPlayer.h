#pragma once
#include "Player.h"
#include "Coordinate.h"

namespace BattleshipGame
{
	class EnemyPlayer : Player
	{
	public:
		EnemyPlayer();
		EnemyPlayer(BattleshipBoard _board, vector<Battleship*> _ships);
		
		vector<Battleship*> GetShips() override;
		Coordinate TakeTurn();
	};
}