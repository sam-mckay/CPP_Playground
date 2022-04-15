#pragma once
#include "Battleship.h"
#include "BattleshipBoard.h"
#include <list>
#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace BattleshipGame
{
	class Player
	{
	protected:
		list<Coordinate> previousTargets;
		BattleshipBoard board;
	public:
		vector<Battleship*> ships;
		
		list<Coordinate> GetPreviousTargets() { return previousTargets; };
		
		Player();
		Player(BattleshipBoard _board, vector<Battleship*> _ships);

		virtual vector<Battleship*> GetShips();
		virtual Coordinate TakeTurn();
		bool ChoosePreciseTarget(Coordinate target);
		Coordinate ChooseRandomTarget();
		bool HasTargetBeenSelectedPreviously(Coordinate target);	
		bool IsTargetValid(Coordinate target);
	};

}