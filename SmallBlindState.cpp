#include "SmallBlindState.h"

std::string SmallBlindState::getName()
{
    return "Small Blind";
}

int SmallBlindState::getTargetScore()
{
    return 100;
}

int SmallBlindState::getRewardMoney()
{
    return 5;
}

BlindState* SmallBlindState::getNextState()
{
    return nullptr;
}