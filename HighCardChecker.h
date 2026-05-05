#pragma once
#include "PokerHandChecker.h"

class HighCardChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking High Card...\n";

        if (hand.presetRank == HandRank::HIGH_CARD) {
            std::cout << "High Card detected!\n";
            return HandRank::HIGH_CARD;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};