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

    // 3. Player chooses up to 5 cards
    std::vector<Card> chosenCards =
        handPlayer.chooseCards(hand.cards);

    // 4. Build selected hand
    Hand selectedHand;
    selectedHand.cards = chosenCards;

    // 5. Display selected hand
    std::cout << "\n--- Selected Hand ---\n";
    handPlayer.playHand(selectedHand);

    // 6. Detect poker hand + calculate score
    int score =
        scoringRule.scoreHand(selectedHand);

    std::cout
        << "\nFinal Score: "
        << score
        << "\n";

    // 7. Check target score
    bool win =
        blindRule.checkBlind(score);

    // 8. Give reward
    rewardManager.giveReward(
        win,
        score,
        money
    );

    // 9. Open shop if player wins
    if (win) {
        shopSystem.openShop(
            money,
            upgrades
        );
    }

    // Debug info
    std::cout << "\n=== Player Status ===\n";

    std::cout
        << "Money: "
        << money.getAmount()
        << "\n";

    std::cout
        << "Bonus Chips: "
        << upgrades.bonusChips
        << "\n";

    std::cout
        << "Bonus Mult: "
        << upgrades.bonusMult
        << "\n";

    std::cout << "\n=== Run Ended ===\n";
}