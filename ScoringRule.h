#pragma once

#include "Hand.h"
#include "HandRank.h"
#include "UpgradeData.h"

class ScoringRule
{
public:
    int scoreHand(
        const Hand& hand,
        const UpgradeData& upgrades
    );

private:
    int convertRankToChips(
        HandRank rank
    );

    int convertRankToMult(
        HandRank rank
    );

    int calculateCardChips(
        const Hand& hand
    );
};