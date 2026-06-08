#include "BlindManager.h"
#include "SmallBlindState.h"

BlindManager::BlindManager()
{
    currentBlind =
        new SmallBlindState();
}

BlindManager::~BlindManager()
{
    delete currentBlind;
}

BlindState* BlindManager::getCurrentBlind()
{
    return currentBlind;
}

void BlindManager::advanceBlind()
{
    BlindState* next =
        currentBlind->getNextState();

    delete currentBlind;

    currentBlind = next;
}

void BlindManager::skipBlind()
{
    advanceBlind();
}