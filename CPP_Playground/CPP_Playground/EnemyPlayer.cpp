#include "EnemyPlayer.h"

namespace BattleshipGame
{
	BattleshipGame::EnemyPlayer::EnemyPlayer()
	{
	}

	BattleshipGame::EnemyPlayer::EnemyPlayer(BattleshipBoard _board, list<Battleship> _ships) : Player::Player(_board, _ships)
	{
	}

	list<Battleship> EnemyPlayer::GetShips()
	{
		return Player::GetShips();
	}

	Coordinate BattleshipGame::EnemyPlayer::TakeTurn()
	{
		return ChooseRandomTarget();

	}
}