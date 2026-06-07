#pragma once
#include "PokerHandChecker.h"
#include <vector>
#include <algorithm>

class StraightFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Straight Flush...\n";

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

        // Straight
        std::vector<int> ranks;

        for (const auto& card : hand.cards) {
            ranks.push_back(card.rank);
        }

        std::sort(ranks.begin(), ranks.end());

        bool isStraight = true;

        for (size_t i = 1; i < ranks.size(); i++) {
            if (ranks[i] != ranks[i - 1] + 1) {
                isStraight = false;
                break;
            }
        }

        if (isFlush && isStraight) {
            std::cout << "Straight Flush detected!\n";
            return HandRank::STRAIGHT_FLUSH;
        }

        if (nextChecker != nullptr)
            return nextChecker->check(hand);

        return HandRank::HIGH_CARD;
    }
};