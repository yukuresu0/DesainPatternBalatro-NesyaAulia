#include "ShopFactory.h"

#include "AddChipsCommand.h"
#include "AddMultCommand.h"
#include "PairMultJokerCommand.h"
#include "FlushBonusJokerCommand.h"
#include "LuckyMoneyJokerCommand.h"

ShopCommand* ShopFactory::createItem(
    int choice
) {
    switch (choice) {
        case 1:
            return new AddChipsCommand();

        case 2:
            return new AddMultCommand();

        case 3:
            return new PairMultJokerCommand();

        case 4:
            return new FlushBonusJokerCommand();
            
        case 5:
            return new LuckyMoneyJokerCommand();

        default:
            return nullptr;
    }
}