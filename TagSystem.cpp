#include "TagSystem.h"

#include <iostream>
#include <cstdlib>

void TagSystem::giveRandomTag(
    UpgradeData& upgrades
)
{
    int tag =
        rand() % 3;

    switch(tag)
    {
        case 0:
            upgrades.bonusChips += 10;

            std::cout
                << "\nTAG: Lucky You"
                << "\n+10 Chips\n";
            break;

        case 1:
            upgrades.bonusMult += 2;

            std::cout
                << "\nTAG: More Mult"
                << "\n+2 Mult\n";
            break;

        case 2:
            upgrades.bonusMoneyPerBlind += 5;

            std::cout
                << "\nTAG: Wish You Wealth"
                << "\n+5 Money every blind win\n";
            break;
    }
}