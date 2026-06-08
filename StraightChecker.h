#pragma once
#include "PokerHandChecker.h"
#include <vector>
#include <algorithm>

class StraightChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Straight...\n";

        if (hand.cards.size() < 5) {
            if (nextChecker != nullptr) {
                return nextChecker->check(hand);
            }

            return HandRank::HIGH_CARD;
        }

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

        if (isStraight) {
            std::cout << "Straight detected!\n";
            return HandRank::STRAIGHT;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};