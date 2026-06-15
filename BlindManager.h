#pragma once
#include "BlindState.h"

class BlindManager
{
private:
    BlindState* currentBlind;

public:
    BlindManager();

    ~BlindManager();

    BlindState* getCurrentBlind();

    void advanceBlind();

    void skipBlind();
};