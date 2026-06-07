#pragma once
#include "Hand.h"
#include "HandRank.h"

class ScoringRule {
public:
    int scoreHand(const Hand& hand);
    int convertRankToScore(HandRank rank);
};