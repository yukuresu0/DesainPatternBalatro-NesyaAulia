#include "JokerManager.h"

void JokerManager::addJoker(
    Joker* joker
)
{
    jokers.push_back(joker);
}

int JokerManager::getTotalBonusChips(
    HandRank rank
)
{
    int total = 0;

    for(Joker* joker : jokers)
    {
        total +=
            joker->getBonusChips(rank);
    }

    return total;
}

int JokerManager::getTotalBonusMult(
    HandRank rank
)
{
    int total = 0;

    for(Joker* joker : jokers)
    {
        total +=
            joker->getBonusMult(rank);
    }

    return total;
}