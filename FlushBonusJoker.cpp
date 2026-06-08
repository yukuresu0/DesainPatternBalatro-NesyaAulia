#include "FlushBonusJoker.h"

int FlushBonusJoker::getBonusChips(
    HandRank rank
)
{
    if(rank == HandRank::FLUSH)
    {
        return 50;
    }

    return 0;
}

int FlushBonusJoker::getBonusMult(
    HandRank rank
)
{
    return 0;
}