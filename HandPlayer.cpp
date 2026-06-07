#include "HandPlayer.h"
#include <iostream>
#include <set>
#include <string>

std::string rankToString(int rank) {
    switch (rank) {
        case 1:  return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return std::to_string(rank);
    }
}

std::string suitToString(int suit) {
    switch (suit) {
        case 0: return "Spades";
        case 1: return "Hearts";
        case 2: return "Diamonds";
        case 3: return "Clubs";
        default: return "?";
    }
}

void HandPlayer::playHand(const Hand& hand) {
    std::cout << "Cards:\n";

    for (int i = 0; i < hand.cards.size(); i++) {
        std::cout
            << i
            << ": "
            << rankToString(hand.cards[i].rank)
            << " of "
            << suitToString(hand.cards[i].suit)
            << "\n";
    }
}

std::vector<Card> HandPlayer::chooseCards(
    const std::vector<Card>& cards
) {
    std::vector<Card> chosen;
    std::set<int> selectedIndexes;

    std::cout << "\nChoose up to 5 cards.\n";
    std::cout << "Enter card index.\n";
    std::cout << "Enter -1 when finished.\n\n";

    while (chosen.size() < 5) {
        int index;

        std::cout
            << "Choose card #"
            << (chosen.size() + 1)
            << ": ";

        std::cin >> index;

        if (index == -1) {
            break;
        }

        if (index < 0 ||
            index >= static_cast<int>(cards.size())) {
            std::cout << "Invalid index.\n";
            continue;
        }

        if (selectedIndexes.count(index)) {
            std::cout << "Card already selected.\n";
            continue;
        }

        selectedIndexes.insert(index);
        chosen.push_back(cards[index]);
    }

    if (chosen.empty()) {
        std::cout
            << "No cards selected. Automatically choosing first card.\n";

        chosen.push_back(cards[0]);
    }

    return chosen;
}