#include <iostream>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::cout << "Generating hand...\n";

    Hand hand;
    hand.value = 6; // dummy: misalnya dianggap FLUSH

    return hand;
}