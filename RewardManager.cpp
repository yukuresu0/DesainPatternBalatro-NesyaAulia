#include "RewardManager.h"
#include <iostream>

int RewardManager::calculateReward(
    int score
) {
    return score / 10;
}

void RewardManager::giveReward(
    bool win,
    int score,
    Money& money
) {
    if (!win) {
        std::cout
            << "No reward earned.\n";

        return;
    }

    int reward =
        calculateReward(score);

    money.add(reward);

    std::cout
        << "Reward earned: "
        << reward
        << "\n";

    std::cout
        << "Current money: "
        << money.getAmount()
        << "\n";
}