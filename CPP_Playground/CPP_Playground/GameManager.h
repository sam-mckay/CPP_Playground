#pragma once
#include "Player.h"
#include "EnemyPlayer.h"
#include "Turn.h"

namespace BattleshipGame
{
	class GameManager
	{
	private: 
		BattleshipBoard playerBoard;
		BattleshipBoard aiBoard;

		list<Battleship> playerShips;
		list<Battleship> aiPlayerShips;

	public:
		bool isActive;
		Player player;
		EnemyPlayer aiPlayer;
		int turnCap;
		int turnCount;

		Turn turn;

		GameManager();

		void NextTurn();
		void NewGame(int shipCount, int boardX, int boardY, int _turnCap = 10);
		void HandleHit(Coordinate target);

		//DEBUG
		void DEBUG_PrintShipLocations();
	};
}
