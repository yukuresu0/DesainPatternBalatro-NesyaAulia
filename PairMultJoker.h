#pragma once

#include "Joker.h"

class PairMultJoker : public Joker
{
public:
    int getBonusChips(
        HandRank rank
    ) override;

    int getBonusMult(
        HandRank rank
    ) override;
};