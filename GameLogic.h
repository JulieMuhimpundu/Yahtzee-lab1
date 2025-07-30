#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include <map>
#include "Die.h"

class GameLogic {
    std::vector<Die> dice;
    int rollsLeft;
    std::map<std::string, int> scores;
    bool categoriesUsed[13] = { false };

    int sumOfValues(int value) const;
    int sumAllDice() const;
    bool checkFullHouse() const;
    bool checkStraight(bool small) const;
public:
    GameLogic();
    void startNewTurn();
    void rollDice(const std::vector<bool>& reroll);
    bool scoreCategory(int category);
    bool isGameOver() const;
    int getTotalScore() const;
    int getRollsLeft() const;
    const std::vector<Die>& getDice() const;
    const std::map<std::string, int>& getScores() const;
};

#endif