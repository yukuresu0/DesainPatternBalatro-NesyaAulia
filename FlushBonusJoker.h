#pragma once

#include "Joker.h"

class FlushBonusJoker : public Joker
{
public:
    int getBonusChips(
        HandRank rank
    ) override;

    int getBonusMult(
        HandRank rank
    ) override;
};