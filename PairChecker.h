#pragma once
#include "PokerHandChecker.h"

class PairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Pair...\n";

        if (hand.presetRank == HandRank::PAIR) {
            std::cout << "Pair detected!\n";
            return HandRank::PAIR;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};