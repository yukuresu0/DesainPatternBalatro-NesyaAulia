#pragma once

#include "ShopCommand.h"

class AddChipsCommand : public ShopCommand {
public:
    void execute(
        UpgradeData& upgrades
    ) override;
};