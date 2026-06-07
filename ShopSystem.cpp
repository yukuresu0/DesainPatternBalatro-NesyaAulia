#include "ShopSystem.h"

#include <iostream>

#include "ShopFactory.h"

void ShopSystem::openShop(
    Money& money,
    UpgradeData& upgrades
) {
    std::cout << "\n=== SHOP ===\n";

    std::cout
        << "Money: "
        << money.getAmount()
        << "\n\n";

    std::cout
        << "1. +10 Chips (Cost 5)\n";

    std::cout
        << "2. +1 Mult (Cost 10)\n";

    std::cout
        << "0. Exit\n";

    int choice;
    std::cin >> choice;

    if (choice == 0) {
        return;
    }

    int cost = 0;

    switch (choice) {
        case 1:
            cost = 5;
            break;

        case 2:
            cost = 10;
            break;

        default:
            std::cout
                << "Invalid choice.\n";
            return;
    }

    if (!money.spend(cost)) {
        std::cout
            << "Not enough money!\n";
        return;
    }

    ShopFactory factory;

    ShopCommand* item =
        factory.createItem(choice);

    if (item != nullptr) {
        item->execute(upgrades);

        std::cout
            << "Purchase successful!\n";

        std::cout
            << "Bonus Chips: "
            << upgrades.bonusChips
            << "\n";

        std::cout
            << "Bonus Mult: "
            << upgrades.bonusMult
            << "\n";

        delete item;
    }
}