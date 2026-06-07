#include "AddChipsCommand.h"

void AddChipsCommand::execute(
    UpgradeData& upgrades
) {
    upgrades.bonusChips += 10;
}