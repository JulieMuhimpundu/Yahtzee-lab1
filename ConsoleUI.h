#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <vector>
#include <string>

class ConsoleUI {
public:
    void displayWelcome() const;
    void displayDice(const std::vector<int>& dice) const;
    std::vector<bool> getRerollSelection(int diceCount) const;
    int getScoringChoice() const;
    void displayScoreOptions() const;
    void displayFinalScore(int score) const;
};

#endif