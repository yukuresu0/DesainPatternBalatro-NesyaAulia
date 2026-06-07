#include "BigBlindState.h"

std::string BigBlindState::getName()
{
    return "Big Blind";
}

int BigBlindState::getTargetScore()
{
    return 200;
}

int BigBlindState::getRewardMoney()
{
    return 10;
}

BlindState* BigBlindState::getNextState()
{
    return nullptr;
}