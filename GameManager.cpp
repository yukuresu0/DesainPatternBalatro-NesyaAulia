#include <iostream>
#include "GameManager.h"

void GameManager::runSession() {
    std::cout << "=== Run Started ===\n";

    // 1. Generate 8 kartu
    Hand hand = handGenerator.generateHand();

    // 2. Tampilkan kartu ke player
    handPlayer.playHand(hand);

    // 3. Player memilih 5 kartu dari 8
    std::vector<Card> chosenCards = handPlayer.chooseCards(hand.cards);

    // 4. Bentuk hand baru dari kartu terpilih
    Hand selectedHand;
    selectedHand.cards = chosenCards;

    std::cout << "\n--- Selected Hand ---\n";
    handPlayer.playHand(selectedHand);

    // 5. Hitung skor
    int score = scoringRule.scoreHand(selectedHand);

    // 6. Cek menang / kalah
    bool win = blindRule.checkBlind(score);

    // 7. Hitung reward
    int reward = rewardRule.earnMoney(win, score);

    // 8. Output hasil
    std::cout << "Money gained: " << reward << "\n";
    std::cout << "=== Run Ended ===\n";
}