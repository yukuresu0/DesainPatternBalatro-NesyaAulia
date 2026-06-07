#include "ShopFactory.h"

#include "AddChipsCommand.h"
#include "AddMultCommand.h"

ShopCommand* ShopFactory::createItem(
    int choice
) {
    switch (choice) {
        case 1:
            return new AddChipsCommand();

        case 2:
            return new AddMultCommand();

        default:
            return nullptr;
    }
}