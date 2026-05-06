#include <iostream>
#include "BlindRule.h"

bool BlindRule::checkBlind(int score) {
    std::cout << "Checking blind...\n";

    if (score >= 10) {
        std::cout << "Result: WIN\n";
        return true;
    }

    std::cout << "Result: LOSE\n";
    return false;
}