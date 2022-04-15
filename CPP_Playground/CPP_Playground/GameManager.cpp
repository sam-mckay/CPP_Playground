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
	if (turnCount >= turnCap)
	{
		isActive = false;
		cout << "Game ended on turn " << turnCount << " as it took too many turns" << endl;
	}

	Coordinate selectedTarget;

	switch (turn)
	{
	case Turn::Player1:
		selectedTarget = player.TakeTurn();		
		break;
	case Turn::Player2:
		selectedTarget = aiPlayer.TakeTurn();	
		break;
	default:
		break;
	}

	HandleHit(selectedTarget);

	turnCount++;
}

void BattleshipGame::GameManager::NewGame(int shipCount, int boardX, int boardY, int _turnCap)
{
	isActive = true;
	playerBoard = BattleshipBoard(boardX, boardY);
	aiBoard = BattleshipBoard(boardX, boardY);

	playerShips = playerBoard.GenerateShips(shipCount, 3);
	aiPlayerShips = aiBoard.GenerateShips(shipCount, 3);

	player = Player(playerBoard, playerShips);
	aiPlayer = EnemyPlayer(aiBoard, aiPlayerShips);

	turnCap = _turnCap;

	DEBUG_PrintShipLocations();
}

void BattleshipGame::GameManager::DEBUG_PrintShipLocations() 
{
	cout << "Player 1's Ships" << endl;
	int index = 0;
	for (Battleship* ship : player.GetShips())
	{
		cout << "Ship " << index << endl;
		cout << "    Location: " << ship->location.x << "," << ship->location.y << endl;
		cout << "    Direction: " << (int)ship->direction << endl;
		cout << "    Size: " << ship->size;
		
		for (Coordinate shipCoord : ship->GetCellsOccupiedByShip())
		{
			cout << "    " << shipCoord.x << "," << shipCoord.y;
		}
		cout << endl;
		cout << endl;
		index++;
	}

	cout << "Player 2's Ships" << endl;
	index = 0;
	for (Battleship* ship : aiPlayer.GetShips())
	{
		cout << "Ship " << index << endl;
		cout << "    Location: " << ship->location.x << "," << ship->location.y << endl;
		cout << "    Direction: " << (int)ship->direction << endl;
		cout << "    Size: " << ship->size;

		for (Coordinate shipCoord : ship->GetCellsOccupiedByShip())
		{
			cout << "    " << shipCoord.x << "," << shipCoord.y;
		}
		cout << endl;
		index++;
	}

	cout << endl;
	cout << endl;
	cout << endl;
}

void BattleshipGame::GameManager::HandleHit(Coordinate target)
{
	int destroyedShips = 0;

	for (int i = 0; i < playerShips.size(); i++)
	{
		Battleship *ship = playerShips[i];
		if (ship->CheckIfHit(target))
		{
			cout << "Player " << (int)turn + 1 << "'s ship " << ship->id <<  " was hit! " << target.x << "," << target.y << endl;
			if (ship->CheckIfDestroyed())
			{
				destroyedShips++;
				cout << "Ship was destroyed!!! " << endl;
			}
			cout << "Post Hit: Hit Count: " << ship->CheckHitCount() << endl;
		}
	}

	if (destroyedShips == playerShips.size())
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
