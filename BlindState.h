#pragma once

#include <string>

class BlindState
{
public:
    virtual ~BlindState() = default;

    virtual std::string getName() = 0;
    virtual int getTargetScore() = 0;
    virtual int getRewardMoney() = 0;

    virtual BlindState* getNextState() = 0;
};