#include "Player.h"


namespace BattleshipGame
{
    Player::Player()
    {
    }
    Player::Player(BattleshipBoard _board, vector<Battleship*> _ships)
    {
        board = _board;
        ships = _ships;

        srand(time(NULL));
    }

    vector<Battleship*> Player::GetShips()
    {
        return ships;
    }

    Coordinate Player::TakeTurn()
    {
        return ChooseRandomTarget();
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
                cout << "Target is outside the board range" << endl;
                return false;
            }
        }
        else
        {
            //Target already selected
            cout << "Target has been selected previously" << endl;
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
            target = board.GenerateRandomCoordinate();

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
        if (board.IsCoordinateOnBoard(target))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}