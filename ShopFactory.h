#pragma once

#include "ShopCommand.h"

class ShopFactory {
public:
    ShopCommand* createItem(
        int choice
    );
};