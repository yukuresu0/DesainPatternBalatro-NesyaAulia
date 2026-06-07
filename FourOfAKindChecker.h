#pragma once
#include "PokerHandChecker.h"

class FourOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Four of a Kind...\n";

        for (size_t i = 0; i < hand.cards.size(); i++) {
            int count = 0;

            for (size_t j = 0; j < hand.cards.size(); j++) {
                if (hand.cards[i].rank == hand.cards[j].rank) {
                    count++;
                }
            }

            if (count >= 4) {
                std::cout << "Four of a Kind detected!\n";
                return HandRank::FOUR_OF_A_KIND;
            }
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};