#include "Player.h"


namespace BattleshipGame
{
    Player::Player()
    {
    }
    Player::Player(BattleshipBoard _board)
    {
        board = _board;
        srand(time(NULL));
    }

    void Player::TakeTurn()
    {
    }

    Coordinate Player::ChooseTarget()
    {
        if (previousTargets.size() == board.MaxCellsInBoard())
        {
            //Early Exit, there are no possible targets;
            return Coordinate(-1,-1);
        }

        Coordinate target;
        do
        {
            int x = rand() % board.rows + 0;
            int y = rand() % board.columns + 0;

            target = Coordinate(x, y);            

        } while (HasTargetBeenSelectedPreviously(target));
        
        if (!HasTargetBeenSelectedPreviously(target))
        {
            previousTargets.push_back(target);
        }

        return target;
    }

    bool Player::HasTargetBeenSelectedPreviously(Coordinate target)
    {
        for (Coordinate previousTarget : previousTargets)
        {
            if (previousTarget == target)
            {
                return true;
            }
        }
        return false;
    }
}