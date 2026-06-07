#include "Deck.h"
#include <algorithm>
#include <random>

void Deck::initialize() {
    cards.clear();

    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            cards.push_back({rank, suit});
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

std::vector<Card> Deck::draw(int n) {
    std::vector<Card> result;

    for (int i = 0; i < n; i++) {
        result.push_back(cards.back());
        cards.pop_back();
    }

    return result;
}