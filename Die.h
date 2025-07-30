#ifndef DIE_H
#define DIE_H

#include <random>

class Die {
    int faceValue;
    const int sides = 6;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> dis;
public:
    Die();
    void roll();
    int getValue() const;
};

#endif