#pragma once

#include "ShopCommand.h"

class AddMultCommand : public ShopCommand {
public:
    void execute(
        UpgradeData& upgrades
    ) override;
};