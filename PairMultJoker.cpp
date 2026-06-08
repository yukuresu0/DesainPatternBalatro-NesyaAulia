#include "PairMultJoker.h"

int PairMultJoker::getBonusChips(
    HandRank rank
)
{
    return 0;
}

int PairMultJoker::getBonusMult(
    HandRank rank
)
{
    if(rank == HandRank::PAIR)
    {
        return 4;
    }

    return 0;
}