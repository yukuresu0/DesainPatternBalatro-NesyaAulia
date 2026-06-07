#pragma once

class Money {
private:
    int amount;

public:
    Money();

    int getAmount() const;

    void add(int value);

    bool spend(int value);
};