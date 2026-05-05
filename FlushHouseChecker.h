#pragma once
#include "PokerHandChecker.h"

class FlushHouseChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Flush House...\n";

        if (hand.presetRank == HandRank::FLUSH_HOUSE) {
            std::cout << "Flush House detected!\n";
            return HandRank::FLUSH_HOUSE;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};