#include "Die.h"

std::mt19937 Die::gen(std::random_device{}());
std::uniform_int_distribution<> Die::dis(1, 6);

Die::Die() : faceValue(1) {}

void Die::roll() {
    faceValue = dis(gen);
}

int Die::getValue() const {
    return faceValue;
}