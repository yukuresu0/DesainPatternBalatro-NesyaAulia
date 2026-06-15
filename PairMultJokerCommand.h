#pragma once

#include "ShopCommand.h"

class PairMultJokerCommand : public ShopCommand
{
public:
    void execute(
        UpgradeData& upgrades
    ) override;
};