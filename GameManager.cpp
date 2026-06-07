#include <iostream>
#include <vector>

#include "GameManager.h"

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    // 1. Generate 8 cards
    Hand hand = handGenerator.generateHand();

    // 2. Display generated cards
    std::cout << "\n--- Generated Cards ---\n";
    handPlayer.playHand(hand);

    // 3. Player chooses 5 cards
    std::vector<Card> chosenCards =
        handPlayer.chooseCards(hand.cards);

    // 4. Build selected hand
    Hand selectedHand;
    selectedHand.cards = chosenCards;

    // 5. Display selected hand
    std::cout << "\n--- Selected Hand ---\n";
    handPlayer.playHand(selectedHand);

    // 6. Calculate score
    int score =
        scoringRule.scoreHand(selectedHand);

    // 7. Check win / lose
    bool win =
        blindRule.checkBlind(score);

    // 8. Calculate reward
    int reward =
        rewardRule.earnMoney(win, score);

    // 9. Final result
    std::cout << "Money gained: "
              << reward
              << std::endl;

    std::cout << "=== Run Ended ===\n";
}