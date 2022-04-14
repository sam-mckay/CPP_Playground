#include "GameManager.h"

BattleshipGame::GameManager::GameManager()
{
	isActive = false;
	player = Player();
	aiPlayer = EnemyPlayer();
	turn = Turn::Player1;	
}

void BattleshipGame::GameManager::NextTurn()
{
	if (turnCount > turnCap)
	{
		isActive = false;
		cout << "Game Ended as it took too many turns" << endl;
	}

	Coordinate selectedTarget;
	list<Battleship> ships;

	switch (turn)
	{
	case Turn::Player1:
		selectedTarget = player.TakeTurn();		
		ships = player.GetShips();
		break;
	case Turn::Player2:
		selectedTarget = aiPlayer.TakeTurn();		
		ships = aiPlayer.GetShips();
		break;
	default:
		break;
	}

	HandleHit(selectedTarget, ships);

	turnCount++;
}

void BattleshipGame::GameManager::NewGame(int shipCount, int boardX, int boardY, int _turnCap)
{
	isActive = true;
	BattleshipBoard playerBoard = BattleshipBoard(boardX, boardY);
	BattleshipBoard aiBoard = BattleshipBoard(boardX, boardY);

	list<Battleship> playerShips = playerBoard.GenerateShips(shipCount, 3);
	list<Battleship> aiPlayerShips = aiBoard.GenerateShips(shipCount, 3);

	player = Player(playerBoard, playerShips);
	aiPlayer = EnemyPlayer(aiBoard, aiPlayerShips);

	turnCap = _turnCap;
}

void BattleshipGame::GameManager::HandleHit(Coordinate target, list<Battleship> ships)
{
	int destroyedShips = 0;

	for (Battleship ship : ships)
	{
		if (ship.CheckIfHit(target))
		{
			if (ship.CheckIfDestroyed())
			{
				destroyedShips++;
			}

		}
	}

	if (destroyedShips == ships.size())
	{
		cout << "Game Over " << endl;

		switch (turn)
		{
		case Turn::Player1:
			cout << "Player 1 Wins" << endl;
			break;
		case Turn::Player2:
			cout << "Player 2 Wins" << endl;
			break;
		default:
			break;
		}

		isActive = false;
	}
}
