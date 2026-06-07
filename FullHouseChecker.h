#pragma once
#include "PokerHandChecker.h"
#include <vector>

class FullHouseChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Full House...\n";

        bool hasThree = false;
        bool hasPair = false;

        std::vector<int> countedRanks;

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

            if (count >= 3) {
                hasThree = true;
            }
            else if (count >= 2) {
                hasPair = true;
            }

            countedRanks.push_back(hand.cards[i].rank);
        }

        if (hasThree && hasPair) {
            std::cout << "Full House detected!\n";
            return HandRank::FULL_HOUSE;
        }

        if (nextChecker != nullptr) {
            return nextChecker->check(hand);
        }

        return HandRank::HIGH_CARD;
    }
};