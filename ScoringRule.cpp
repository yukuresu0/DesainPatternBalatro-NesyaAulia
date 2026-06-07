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

int ScoringRule::scoreHand(
    const Hand& hand,
    const UpgradeData& upgrades
) {
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

    HandRank detectedRank =
        royalFlush.check(hand);

    std::cout
        << "Final Hand: "
        << handRankToString(detectedRank)
        << std::endl;

    int chips =
        convertRankToChips(
            detectedRank
        );

    chips +=
        calculateCardChips(
            hand
        );

    int mult =
        convertRankToMult(
            detectedRank
        );

    chips += upgrades.bonusChips;
    mult += upgrades.bonusMult;

    if (mult < 1) {
        mult = 1;
    }

    int finalScore =
        chips * mult;

    std::cout
        << "Card Chips: "
        << calculateCardChips(hand)
        << std::endl;

    std::cout
        << "Chips: "
        << chips
        << std::endl;

    std::cout
        << "Mult: "
        << mult
        << std::endl;

    std::cout
        << "Final Score: "
        << finalScore
        << std::endl;

    return finalScore;
}

int ScoringRule::calculateCardChips(
    const Hand& hand
) {
    int total = 0;

    for (const Card& card : hand.cards) {

        switch (card.rank) {

            case 1: // Ace
                total += 11;
                break;

            case 11: // Jack
            case 12: // Queen
            case 13: // King
                total += 10;
                break;

            default:
                total += card.rank;
                break;
        }
    }

    return total;
}

int ScoringRule::convertRankToChips(
    HandRank rank
) {
    switch(rank) {

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

        case HandRank::ROYAL_FLUSH:
            return 100;

        case HandRank::FIVE_OF_A_KIND:
            return 90;

        case HandRank::FLUSH_HOUSE:
            return 95;

        case HandRank::FLUSH_FIVE:
            return 110;

        default:
            return 0;
    }
}

int ScoringRule::convertRankToMult(
    HandRank rank
) {
    switch(rank) {

        case HandRank::HIGH_CARD:
            return 1;

        case HandRank::PAIR:
            return 2;

        case HandRank::TWO_PAIR:
            return 2;

        case HandRank::THREE_OF_A_KIND:
            return 3;

        case HandRank::STRAIGHT:
            return 4;

        case HandRank::FLUSH:
            return 4;

        case HandRank::FULL_HOUSE:
            return 5;

        case HandRank::FOUR_OF_A_KIND:
            return 7;

        case HandRank::STRAIGHT_FLUSH:
            return 8;

        case HandRank::ROYAL_FLUSH:
            return 10;

        case HandRank::FIVE_OF_A_KIND:
            return 9;

        case HandRank::FLUSH_HOUSE:
            return 9;

        case HandRank::FLUSH_FIVE:
            return 11;

        default:
            return 1;
    }
}