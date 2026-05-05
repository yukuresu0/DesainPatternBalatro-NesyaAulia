#pragma once
#include "Hand.h"
#include "HandRank.h"
#include <iostream>

class PokerHandChecker {
protected:
    PokerHandChecker* nextChecker = nullptr;

public:
    virtual ~PokerHandChecker() {}

    void setNext(PokerHandChecker* next) {
        nextChecker = next;
    }

    virtual HandRank check(const Hand& hand) = 0;
};