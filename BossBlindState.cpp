#include "BossBlindState.h"

std::string BossBlindState::getName()
{
    return "Boss Blind";
}

int BossBlindState::getTargetScore()
{
    return 400;
}

int BossBlindState::getRewardMoney()
{
    return 20;
}

BlindState* BossBlindState::getNextState()
{
    return nullptr;
}