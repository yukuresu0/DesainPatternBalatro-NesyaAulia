#include <iostream>
#include "GameManager.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(nullptr));
    std::cout << "=== Poker Hand Checker Demo ===\n\n";

    GameManager gameManager;
    gameManager.runSession();

    std::cout << "\n=== End of Session ===\n";

    return 0;
}