#pragma once
#include "PokerHandChecker.h"

class FourOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Four of a Kind...\n";

        if (hand.presetRank == HandRank::FOUR_OF_A_KIND) {
            std::cout << "Four of a Kind detected!\n";
            return HandRank::FOUR_OF_A_KIND;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};