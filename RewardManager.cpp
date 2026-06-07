#include "RewardManager.h"
#include <iostream>

void RewardManager::giveReward(
    int reward,
    Money& money
) {
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