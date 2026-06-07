#pragma once

#include "BlindState.h"

class BossBlindState : public BlindState
{
public:
    std::string getName() override;

    int getTargetScore() override;

    int getRewardMoney() override;

    BlindState* getNextState() override;
};