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
#include "HandScoreTable.h"

int ScoringRule::scoreHand(const Hand& hand) {
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

    HandRank detectedRank = royalFlush.check(hand);

    std::cout << "Final Hand: " << handRankToString(detectedRank) << std::endl;

    HandScoreData scoreData =
    HandScoreTable::getScoreData(
        detectedRank
    );

int finalScore =
    scoreData.chips
    * scoreData.mult;

std::cout
    << "Chips: "
    << scoreData.chips
    << std::endl;

std::cout
    << "Mult: "
    << scoreData.mult
    << std::endl;

std::cout
    << "Final Score: "
    << finalScore
    << std::endl;

return finalScore;
}
