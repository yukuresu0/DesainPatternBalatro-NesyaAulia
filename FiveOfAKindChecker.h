#pragma once
#include "PokerHandChecker.h"

class FiveOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Five Of A Kind...\n";

        if (hand.presetRank == HandRank::FLUSH) {
            std::cout << "Five Of A Kind detected!\n";
            return HandRank::FIVE_OF_A_KIND;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};