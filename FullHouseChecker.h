#pragma once
#include "PokerHandChecker.h"

class FullHouseChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Full House...\n";

        if (hand.presetRank == HandRank::FULL_HOUSE) {
            std::cout << "Full House detected!\n";
            return HandRank::FULL_HOUSE;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};