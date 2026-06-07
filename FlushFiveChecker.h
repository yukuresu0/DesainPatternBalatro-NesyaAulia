#pragma once
#include "PokerHandChecker.h"

class FlushFiveChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Flush Five...\n";

        if (hand.cards.size() < 5) {
            if (nextChecker != nullptr)
                return nextChecker->check(hand);

            return HandRank::HIGH_CARD;
        }

        // Flush
        int firstSuit = hand.cards[0].suit;
        bool isFlush = true;

        for (size_t i = 1; i < hand.cards.size(); i++) {
            if (hand.cards[i].suit != firstSuit) {
                isFlush = false;
                break;
            }
        }

        // Five Of A Kind
        bool hasFive = false;

        for (size_t i = 0; i < hand.cards.size(); i++) {
            int count = 0;

            for (size_t j = 0; j < hand.cards.size(); j++) {
                if (hand.cards[i].rank == hand.cards[j].rank) {
                    count++;
                }
            }

            if (count >= 5) {
                hasFive = true;
                break;
            }
        }

        if (isFlush && hasFive) {
            std::cout << "Flush Five detected!\n";
            return HandRank::FLUSH_FIVE;
        }

        if (nextChecker != nullptr)
            return nextChecker->check(hand);

        return HandRank::HIGH_CARD;
    }
};