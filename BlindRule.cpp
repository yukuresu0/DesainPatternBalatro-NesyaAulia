#include <iostream>
#include "BlindRule.h"

bool BlindRule::checkBlind(
    int score,
    int targetScore
) {
    std::cout << "Checking blind...\n";
    std::cout << "Target Score: "
              << targetScore
           << std::endl;

    if (score >= targetScore) {
        std::cout << "Result: WIN\n";
        return true;
    }

    std::cout << "Result: LOSE\n";
    return false;
}