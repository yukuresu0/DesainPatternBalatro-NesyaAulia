#include "HandPlayer.h"
#include <iostream>

void HandPlayer::playHand(const Hand& hand) {
    std::cout << "Cards:\n";
    for (int i = 0; i < hand.cards.size(); i++) {
        std::cout << i << ": Rank " << hand.cards[i].rank
                  << ", Suit " << hand.cards[i].suit << "\n";
    }
}

std::vector<Card> HandPlayer::chooseCards(const std::vector<Card>& cards) {
    std::cout << "Choosing 5 cards...\n";

    std::vector<Card> chosen;

    for (int i = 0; i < 5; i++) {
        chosen.push_back(cards[i]); // sementara auto
    }

    return chosen;
}