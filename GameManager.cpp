#include "GameManager.h"

#include <iostream>
#include <vector>

#include "SmallBlindState.h"

void GameManager::runSession()
{
    std::cout
        << "=== Run Started ===\n";

    BlindState* currentBlind =
        new SmallBlindState();

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

        // Draw 8 cards
        Hand hand =
            handGenerator.generateHand();

        std::cout
            << "\n--- Generated Cards ---\n";

        handPlayer.playHand(hand);

        // Choose up to 5 cards
        std::vector<Card> chosenCards =
            handPlayer.chooseCards(
                hand.cards
            );

        Hand selectedHand;
        selectedHand.cards =
            chosenCards;

        std::cout
            << "\n--- Selected Hand ---\n";

        handPlayer.playHand(
            selectedHand
        );

        // Score
        int score =
            scoringRule.scoreHand(
                selectedHand,
                upgrades
            );

        std::cout
            << "\nFinal Score: "
            << score
            << "\n";

        // Check blind
        bool win =
            blindRule.checkBlind(
                score,
                currentBlind->getTargetScore()
            );

        if (!win)
        {
            std::cout
                << "\nRun Failed!\n";

            delete currentBlind;
            currentBlind = nullptr;

            break;
        }

        // Reward
        rewardManager.giveReward(
            currentBlind->getRewardMoney(),
            money
        );

        // Shop
        shopSystem.openShop(
            money,
            upgrades
        );

        BlindState* nextBlind =
            currentBlind->getNextState();

        delete currentBlind;

        currentBlind =
            nextBlind;
    }

    std::cout
        << "\n=== Run Ended ===\n";
}