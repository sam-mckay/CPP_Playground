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
		ships = player.ships;
		break;
	case Turn::Player2:
		selectedTarget = aiPlayer.TakeTurn();		
		ships = aiPlayer.ships;
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

	player = Player(playerBoard);
	aiPlayer = EnemyPlayer(aiBoard);

	turnCap = _turnCap;
}

void BattleshipGame::GameManager::HandleHit(Coordinate target, list<Battleship> ships)
{

}
