#include "LuckyMoneyJokerCommand.h"

void LuckyMoneyJokerCommand::execute(
    UpgradeData& upgrades
)
{
    upgrades.luckyMoneyJoker = true;
}