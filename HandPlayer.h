#pragma once
#include "Hand.h"
#include <vector>

class HandPlayer {
public:
    void playHand(const Hand& hand);

    std::vector<Card> chooseCards(const std::vector<Card>& cards);
};