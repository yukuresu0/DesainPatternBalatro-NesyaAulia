#pragma once
#include "PokerHandChecker.h"
#include <vector>

class FlushHouseChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        std::cout << "Checking Flush House...\n";

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

        // Full House
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

            if (count >= 3)
                hasThree = true;
            else if (count >= 2)
                hasPair = true;

            countedRanks.push_back(hand.cards[i].rank);
        }

        if (isFlush && hasThree && hasPair) {
            std::cout << "Flush House detected!\n";
            return HandRank::FLUSH_HOUSE;
        }

        if (nextChecker != nullptr)
            return nextChecker->check(hand);

        return HandRank::HIGH_CARD;
    }
};