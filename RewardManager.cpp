#include "RewardManager.h"
#include <iostream>

void RewardManager::giveReward(
    int reward,
    Money& money
)
{
    money.add(reward);

    std::cout
        << "Reward Earned: "
        << reward
        << "\n";

    std::cout
        << "Current Money: "
        << money.getAmount()
        << "\n";
}