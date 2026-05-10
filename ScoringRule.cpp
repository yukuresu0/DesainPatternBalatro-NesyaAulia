#include "ScoringRule.h"
#include <iostream>

#include "RoyalFlushChecker.h"
#include "FlushFiveChecker.h"
#include "FlushHouseChecker.h"
#include "FiveOfAKindChecker.h"
#include "StraightFlushChecker.h"
#include "FourOfAKindChecker.h"
#include "FullHouseChecker.h"
#include "FlushChecker.h"
#include "StraightChecker.h"
#include "ThreeOfAKindChecker.h"
#include "TwoPairChecker.h"
#include "PairChecker.h"
#include "HighCardChecker.h"

int ScoringRule::scoreHand(const Hand& hand) {
    // Chain of Responsibility
    RoyalFlushChecker royalFlush;
    FlushFiveChecker flushFive;
    FlushHouseChecker flushHouse;
    FiveOfAKindChecker fiveOfAKind;
    StraightFlushChecker straightFlush;
    FourOfAKindChecker fourOfAKind;
    FullHouseChecker fullHouse;
    FlushChecker flush;
    StraightChecker straight;
    ThreeOfAKindChecker threeOfAKind;
    TwoPairChecker twoPair;
    PairChecker pair;
    HighCardChecker highCard;

    // Setup checker chain
    royalFlush.setNext(&flushFive);
    flushFive.setNext(&flushHouse);
    flushHouse.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&straightFlush);
    straightFlush.setNext(&fourOfAKind);
    fourOfAKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeOfAKind);
    threeOfAKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);

    // Detect combo
    HandRank detectedRank = royalFlush.check(hand);

    std::cout << "Final Hand: "
              << handRankToString(detectedRank)
              << std::endl;

    // Calculate score
    int baseScore = calculateBaseScore(hand);
    int comboScore = convertRankToScore(detectedRank);

    int finalScore = baseScore + comboScore;

    // Debug output
    std::cout << "Base Score: "
              << baseScore
              << std::endl;

    std::cout << "Combo Bonus: "
              << comboScore
              << std::endl;

    std::cout << "Final Score: "
              << finalScore
              << std::endl;

    return finalScore;
}

int ScoringRule::calculateBaseScore(const Hand& hand) {
    int total = 0;

    for (const auto& card : hand.cards) {
        int value = card.rank;

        // J, Q, K = 10
        if (value > 10) {
            value = 10;
        }

        total += value;
    }

    return total;
}

int ScoringRule::convertRankToScore(HandRank rank) {
    switch (rank) {
        case HandRank::HIGH_CARD:
            return 5;

        case HandRank::PAIR:
            return 10;

        case HandRank::TWO_PAIR:
            return 20;

        case HandRank::THREE_OF_A_KIND:
            return 30;

        case HandRank::STRAIGHT:
            return 40;

        case HandRank::FLUSH:
            return 50;

        case HandRank::FULL_HOUSE:
            return 60;

        case HandRank::FOUR_OF_A_KIND:
            return 70;

        case HandRank::STRAIGHT_FLUSH:
            return 80;

        case HandRank::FIVE_OF_A_KIND:
            return 90;

        case HandRank::FLUSH_HOUSE:
            return 95;

        case HandRank::ROYAL_FLUSH:
            return 100;

        case HandRank::FLUSH_FIVE:
            return 110;

        default:
            return 0;
    }
}