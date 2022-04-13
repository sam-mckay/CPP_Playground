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
        Coordinate target;
        int index = 0;
        do
        {
            int x = rand() % board.rows + 0;
            int y = rand() % board.columns + 0;

            target = Coordinate(x, y);
            

            index++;

        } while (HasTargetBeenSelectedPreviously(target) && index < board.MaxCellsInBoard());
        
        previousTargets.push_back(target);

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