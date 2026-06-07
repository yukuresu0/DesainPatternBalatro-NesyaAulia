#pragma once
#include "PokerHandChecker.h"

class ThreeOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Three of a Kind...\n";

        for (size_t i = 0; i < hand.cards.size(); i++) {
            int count = 0;

            for (size_t j = 0; j < hand.cards.size(); j++) {
                if (hand.cards[i].rank == hand.cards[j].rank) {
                    count++;
                }
            }

            if (count >= 3) {
                std::cout << "Three of a Kind detected!\n";
                return HandRank::THREE_OF_A_KIND;
            }
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};