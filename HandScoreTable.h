#pragma once

#include "HandRank.h"
#include "HandScoreData.h"

class HandScoreTable
{
public:
    static HandScoreData getScoreData(
        HandRank rank
    );
};