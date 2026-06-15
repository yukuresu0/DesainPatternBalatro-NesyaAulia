#pragma once

#include "ShopCommand.h"

class FlushBonusJokerCommand : public ShopCommand
{
public:
    void execute(
        UpgradeData& upgrades
    ) override;
};