#include "PairMultJokerCommand.h"

void PairMultJokerCommand::execute(
    UpgradeData& upgrades
)
{
    upgrades.pairMultJoker = true;
}