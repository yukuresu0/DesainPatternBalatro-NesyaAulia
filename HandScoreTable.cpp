#include "HandScoreTable.h"

HandScoreData HandScoreTable::getScoreData(
    HandRank rank
)
{
    switch(rank)
    {
        case HandRank::HIGH_CARD:
            return {5, 1};

        case HandRank::PAIR:
            return {10, 2};

        case HandRank::TWO_PAIR:
            return {20, 2};

        case HandRank::THREE_OF_A_KIND:
            return {30, 3};

        case HandRank::STRAIGHT:
            return {40, 4};

        case HandRank::FLUSH:
            return {50, 4};

        case HandRank::FULL_HOUSE:
            return {60, 5};

        case HandRank::FOUR_OF_A_KIND:
            return {70, 6};

        case HandRank::STRAIGHT_FLUSH:
            return {80, 7};

        case HandRank::ROYAL_FLUSH:
            return {100, 8};

        case HandRank::FIVE_OF_A_KIND:
            return {90, 7};

        case HandRank::FLUSH_HOUSE:
            return {95, 7};

        case HandRank::FLUSH_FIVE:
            return {110, 8};

        default:
            return {0,1};
    }
}