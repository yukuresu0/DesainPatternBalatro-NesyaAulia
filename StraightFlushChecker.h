#pragma once
#include "PokerHandChecker.h"

class StraightFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Straight Flush...\n";

        if (hand.presetRank == HandRank::STRAIGHT_FLUSH) {
            std::cout << "Straight Flush detected!\n";
            return HandRank::STRAIGHT_FLUSH;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};