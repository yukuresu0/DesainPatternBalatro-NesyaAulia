#pragma once

#include <vector>

#include "Joker.h"

class JokerManager
{
private:
    std::vector<Joker*> jokers;

public:
    void addJoker(
        Joker* joker
    );

    int getTotalBonusChips(
        HandRank rank
    );

    int getTotalBonusMult(
        HandRank rank
    );
};