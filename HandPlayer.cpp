#include <iostream>
#include "HandPlayer.h"

void HandPlayer::playHand(const Hand& hand) {
    std::cout << "Player plays hand with value = " << hand.value << "\n";
}