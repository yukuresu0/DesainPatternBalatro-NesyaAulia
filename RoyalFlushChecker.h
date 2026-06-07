#pragma once
#include "PokerHandChecker.h"
#include <vector>
#include <algorithm>

class RoyalFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Royal Flush...\n";

        if (hand.cards.size() < 5) {
            if (nextChecker != nullptr)
                return nextChecker->check(hand);

            return HandRank::HIGH_CARD;
        }

        // Flush check
        int firstSuit = hand.cards[0].suit;
        bool isFlush = true;

        for (size_t i = 1; i < hand.cards.size(); i++) {
            if (hand.cards[i].suit != firstSuit) {
                isFlush = false;
                break;
            }
        }

        // Rank check
        std::vector<int> ranks;

        for (const auto& card : hand.cards) {
            ranks.push_back(card.rank);
        }

        std::sort(ranks.begin(), ranks.end());

        bool isRoyal =
            ranks[0] == 1 &&
            ranks[1] == 10 &&
            ranks[2] == 11 &&
            ranks[3] == 12 &&
            ranks[4] == 13;

        if (isFlush && isRoyal) {
            std::cout << "Royal Flush detected!\n";
            return HandRank::ROYAL_FLUSH;
        }

        if (nextChecker != nullptr)
            return nextChecker->check(hand);

        return HandRank::HIGH_CARD;
    }
};