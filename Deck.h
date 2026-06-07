#pragma once
#include <vector>
#include "Hand.h"

class Deck {
public:
    std::vector<Card> cards;

    void initialize();
    void shuffle();
    std::vector<Card> draw(int n);
};