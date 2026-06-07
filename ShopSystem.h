#pragma once

#include "Money.h"
#include "UpgradeData.h"

class ShopSystem {
public:
    void openShop(
        Money& money,
        UpgradeData& upgrades
    );
};