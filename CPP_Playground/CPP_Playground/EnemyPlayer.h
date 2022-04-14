#pragma once
#include "Player.h"
#include "Coordinate.h"

namespace BattleshipGame
{
	class EnemyPlayer : Player
	{
	public:
		EnemyPlayer();
		EnemyPlayer(BattleshipBoard _board,list<Battleship> _ships);
		
		list<Battleship> GetShips() override;
		Coordinate TakeTurn();
	};
}