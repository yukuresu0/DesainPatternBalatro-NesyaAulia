#include "Money.h"

Money::Money()
    : amount(0)
{
}

int Money::getAmount() const {
    return amount;
}

void Money::add(int value) {
    amount += value;
}

bool Money::spend(int value) {
    if (amount < value) {
        return false;
    }

    amount -= value;
    return true;
}