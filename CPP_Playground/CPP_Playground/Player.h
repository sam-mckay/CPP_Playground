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
	private:
		list<Coordinate> previousTargets;
		BattleshipBoard board;
	public:
		list<Battleship> ships;
		
		list<Coordinate> GetPreviousTargets() { return previousTargets; };
		
		Player();
		Player(BattleshipBoard _board);
		void TakeTurn();
		bool ChoosePreciseTarget(Coordinate target);
		Coordinate ChooseRandomTarget();
		bool HasTargetBeenSelectedPreviously(Coordinate target);	
		bool IsTargetValid(Coordinate target);
	};

}