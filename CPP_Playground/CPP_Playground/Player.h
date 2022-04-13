#pragma once
#include "Battleship.h"
#include "BattleshipBoard.h"
#include <list>
#include <stdlib.h>
#include <time.h>

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
		Coordinate ChooseTarget();
		bool HasTargetBeenSelectedPreviously(Coordinate target);		
	};

}