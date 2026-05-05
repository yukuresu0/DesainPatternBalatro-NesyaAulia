#pragma once
#include "PokerHandChecker.h"

class FlushFiveChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Flush Five...\n";

        if (hand.presetRank == HandRank::FLUSH_FIVE) {
            std::cout << "Flush Five detected!\n";
            return HandRank::FLUSH_FIVE;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};