#pragma once

#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"

#include "RewardManager.h"
#include "Money.h"

#include "ShopSystem.h"
#include "UpgradeData.h"
#include "BlindManager.h"

class GameManager {
public:
    void runSession();

private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    BlindManager blindManager;

    RewardManager rewardManager;
    Money money;

    ShopSystem shopSystem;
    UpgradeData upgrades;
};