#include "HandGenerator.h"
#include "Deck.h"
#include <iostream>

Hand HandGenerator::generateHand() {
    std::cout << "Generating hand...\n";

    Deck deck;
    deck.initialize();
    deck.shuffle();

    Hand hand;
    hand.cards = deck.draw(8); // 🔥 sekarang 8 kartu

    return hand;
}