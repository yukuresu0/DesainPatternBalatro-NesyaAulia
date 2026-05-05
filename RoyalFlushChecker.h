#pragma once
#include "PokerHandChecker.h"

class RoyalFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Royal Flush...\n";

        if (hand.presetRank == HandRank::ROYAL_FLUSH) {
            std::cout << "Royal Flush detected!\n";
            return HandRank::ROYAL_FLUSH;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};