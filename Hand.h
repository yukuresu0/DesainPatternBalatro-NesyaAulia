#pragma once
#include <vector>
#include "HandRank.h"

struct Card {
    int rank = 0; // 1-13
    int suit = 0; // 0-3
};

struct Hand {
    int value = 0;
    std::vector<Card> cards;
    HandRank presetRank = HandRank::HIGH_CARD;
};