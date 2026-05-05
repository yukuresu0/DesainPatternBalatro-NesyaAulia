#pragma once
#include "PokerHandChecker.h"

class ThreeOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Three of a Kind...\n";

        if (hand.presetRank == HandRank::THREE_OF_A_KIND) {
            std::cout << "Three of a Kind detected!\n";
            return HandRank::THREE_OF_A_KIND;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};