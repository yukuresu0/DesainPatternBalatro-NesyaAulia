#pragma once
#include "PokerHandChecker.h"
#include <vector>

class TwoPairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Two Pair...\n";

        std::vector<int> countedRanks;
        int pairCount = 0;

        for (size_t i = 0; i < hand.cards.size(); i++) {

            bool alreadyCounted = false;

            for (int rank : countedRanks) {
                if (rank == hand.cards[i].rank) {
                    alreadyCounted = true;
                    break;
                }
            }

            if (alreadyCounted)
                continue;

            int count = 0;

            for (size_t j = 0; j < hand.cards.size(); j++) {
                if (hand.cards[i].rank == hand.cards[j].rank) {
                    count++;
                }
            }

            if (count >= 2) {
                pairCount++;
            }

            countedRanks.push_back(hand.cards[i].rank);
        }

        if (pairCount >= 2) {
            std::cout << "Two Pair detected!\n";
            return HandRank::TWO_PAIR;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};