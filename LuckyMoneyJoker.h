#pragma once

#include "Joker.h"

class LuckyMoneyJoker : public Joker
{
public:
    int getBonusChips(
        HandRank rank
    ) override;

    int getBonusMult(
        HandRank rank
    ) override;

    int getBonusMoney();
};