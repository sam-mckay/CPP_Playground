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

    bool Player::ChoosePreciseTarget(Coordinate target)
    {
        if (!HasTargetBeenSelectedPreviously(target))
        {
            if (IsTargetValid(target))
            {
                previousTargets.push_back(target);
                return true;
            }
            else
            {
                //Target invalid
                std::cout << "Target is outside the board range" << endl;
                return false;
            }
        }
        else
        {
            //Target already selected
            std::cout << "Target has been selected previously" << endl;
            return false;
        }
    }

    Coordinate Player::ChooseRandomTarget()
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
    bool Player::IsTargetValid(Coordinate target)
    {
        if (target.x >= board.rows)
        {
            return false;
        }
        else if (target.y >= board.columns)
        {
            return false;
        }
        else if (target.x < 0)
        {
            return false;
        }
        else if (target.y < 0)
        {
            return false;
        }
        return true;
    }
}