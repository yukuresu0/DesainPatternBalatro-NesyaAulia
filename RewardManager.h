#pragma once

#include "Money.h"

class RewardManager {
public:
    void giveReward(
        bool win,
        int score,
        Money& money
    );

private:
    int calculateReward(
        int score
    );
};