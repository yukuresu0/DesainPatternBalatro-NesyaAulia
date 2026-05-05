#pragma once
#include "PokerHandChecker.h"

class StraightChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Straight...\n";

        if (hand.presetRank == HandRank::STRAIGHT) {
            std::cout << "Straight detected!\n";
            return HandRank::STRAIGHT;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};