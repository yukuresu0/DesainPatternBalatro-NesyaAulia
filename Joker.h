#pragma once

#include "HandRank.h"

class Joker
{
public:
    virtual ~Joker() = default;

    virtual int getBonusChips(
        HandRank rank
    ) = 0;

    virtual int getBonusMult(
        HandRank rank
    ) = 0;
};