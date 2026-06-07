#pragma once

#include "UpgradeData.h"

class ShopCommand {
public:
    virtual ~ShopCommand() {}

    virtual void execute(
        UpgradeData& upgrades
    ) = 0;
};