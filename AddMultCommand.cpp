#include "AddMultCommand.h"

void AddMultCommand::execute(
    UpgradeData& upgrades
) {
    upgrades.bonusMult += 1;
}