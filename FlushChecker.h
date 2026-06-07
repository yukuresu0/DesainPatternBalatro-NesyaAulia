#pragma once
#include "PokerHandChecker.h"

class FlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Flush...\n";

if (hand.cards.size() < 5) {
    if (nextChecker != nullptr) {
        return nextChecker->check(hand);
    }

    return HandRank::HIGH_CARD;
}

int firstSuit = hand.cards[0].suit;
bool isFlush = true;

        for (size_t i = 1; i < hand.cards.size(); i++) {
            if (hand.cards[i].suit != firstSuit) {
                isFlush = false;
                break;
            }
        }

        if (isFlush) {
            std::cout << "Flush detected!\n";
            return HandRank::FLUSH;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};