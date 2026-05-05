#pragma once
#include "PokerHandChecker.h"

class TwoPairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Two Pair...\n";

        if (hand.presetRank == HandRank::TWO_PAIR) {
            std::cout << "Two Pair detected!\n";
            return HandRank::TWO_PAIR;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};