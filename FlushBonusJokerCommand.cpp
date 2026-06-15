#include "FlushBonusJokerCommand.h"

void FlushBonusJokerCommand::execute(
    UpgradeData& upgrades
)
{
    upgrades.flushBonusJoker = true;
}