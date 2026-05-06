#pragma once
#include "PokerHandChecker.h"

class FlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Flush...\n";

        if (hand.presetRank == HandRank::FLUSH) {
            std::cout << "Flush detected!\n";
            return HandRank::FLUSH;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};