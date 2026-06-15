#pragma once

#include "ShopCommand.h"

class LuckyMoneyJokerCommand : public ShopCommand
{
public:
    void execute(
        UpgradeData& upgrades
    ) override;
};