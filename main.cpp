#include <iostream>
#include "GameManager.h"

int main() {
    std::cout << "=== Poker Hand Checker Demo ===\n\n";

    GameManager gameManager;
    gameManager.runSession();

    std::cout << "\n=== End of Session ===\n";

    return 0;
}