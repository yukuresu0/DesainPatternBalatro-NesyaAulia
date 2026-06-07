#pragma once
#include "PokerHandChecker.h"

class PairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
    std::cout << "Checking Pair...\n";

    for (size_t i = 0; i < hand.cards.size(); i++) {
        int count = 0;

        for (size_t j = 0; j < hand.cards.size(); j++) {
            if (hand.cards[i].rank == hand.cards[j].rank) {
                count++;
            }
        }

        if (count >= 2) {
            std::cout << "Pair detected!\n";
            return HandRank::PAIR;
        }
    }

    if (nextChecker != nullptr) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}
};