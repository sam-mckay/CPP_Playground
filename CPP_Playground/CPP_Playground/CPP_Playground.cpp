// CPP_Playground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameManager.h"
#include "Battleship.h"
#include "BattleshipBoard.h"
#include "Player.h"
#include "EnemyPlayer.h"
#include "Direction.h"
#include "Turn.h"


using namespace std;

int main()
{
    cout << "Hello World!\n" << endl;


    BattleshipGame::GameManager game;
    game.NewGame(1, 10, 10, 50000);

    while (game.isActive)
    {
        game.NextTurn();
    }

    return 0;
}

/*
    Board
    Cell
    Ships
        Size - Amount of cells
        Direction
        Location - From Rear of ship
    Players
    GameManager
        Turn management
        GameSetup


*/