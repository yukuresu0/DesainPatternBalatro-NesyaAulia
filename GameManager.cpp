#include "GameManager.h"
#include "Deck.h"
#include <iostream>
#include <vector>

#include "SmallBlindState.h"

void GameManager::runSession()
{
    std::cout
        << "=== Run Started ===\n";

    BlindState* currentBlind =
        blindManager.getCurrentBlind();

    while (currentBlind != nullptr)
{
    std::cout
        << "\n=====================\n";

    std::cout
        << currentBlind->getName()
        << "\n";

    std::cout
        << "Target Score: "
        << currentBlind->getTargetScore()
        << "\n";

    std::cout
        << "Reward: "
        << currentBlind->getRewardMoney()
        << "\n";

    std::cout
        << "=====================\n";

    // ===== NEW =====
    Deck deck;
    deck.initialize();
    deck.shuffle();

    Hand currentHand;
    currentHand.cards = deck.draw(8);

    int totalScore = 0;
    int handsRemaining = 4;

    while (
        handsRemaining > 0 &&
        totalScore < currentBlind->getTargetScore()
    )
    {
        std::cout
            << "\nHands Remaining: "
            << handsRemaining
            << "\n";

        std::cout
            << "Total Score: "
            << totalScore
            << "\n";

        std::cout
            << "Deck Remaining: "
            << deck.remainingCards()
            << "\n";

        std::cout
            << "\n--- Current Hand ---\n";

        handPlayer.playHand(currentHand);

        std::vector<Card> chosenCards =
            handPlayer.chooseCards(
                currentHand.cards
            );

        Hand selectedHand;
        selectedHand.cards =
            chosenCards;

        std::cout
            << "\n--- Selected Hand ---\n";

        handPlayer.playHand(
            selectedHand
        );

        int score =
            scoringRule.scoreHand(
                selectedHand,
                upgrades
            );

        totalScore += score;

        std::cout
            << "\nHand Score: "
            << score
            << "\n";

        std::cout
            << "Total Score: "
            << totalScore
            << "\n";

        // Remove played cards from hand
        std::vector<Card> remainingCards;

        for(const Card& handCard : currentHand.cards)
        {
            bool used = false;

            for(const Card& playedCard : chosenCards)
            {
                if(
                    handCard.rank ==
                    playedCard.rank
                    &&
                    handCard.suit ==
                    playedCard.suit
                )
                {
                    used = true;
                    break;
                }
            }

            if(!used)
            {
                remainingCards.push_back(
                    handCard
                );
            }
        }

        currentHand.cards =
            remainingCards;

        // Draw replacement cards
        int needCards =
            8 -
            currentHand.cards.size();

        if(deck.remainingCards() > 0)
        {
            int drawCount =
                std::min(
                    needCards,
                    deck.remainingCards()
                );

            std::vector<Card> newCards =
                deck.draw(drawCount);

            currentHand.cards.insert(
                currentHand.cards.end(),
                newCards.begin(),
                newCards.end()
            );
        }

        handsRemaining--;
    }

    bool win =
        blindRule.checkBlind(
            totalScore,
            currentBlind->getTargetScore()
        );

    if (!win)
    {
        std::cout
            << "\nRun Failed!\n";

        break;
    }

    rewardManager.giveReward(
        currentBlind->getRewardMoney(),
        money
    );

    shopSystem.openShop(
        money,
        upgrades
    );

    blindManager.advanceBlind();

    currentBlind =
        blindManager.getCurrentBlind();
}

    std::cout
        << "\n=== Run Ended ===\n";
}
