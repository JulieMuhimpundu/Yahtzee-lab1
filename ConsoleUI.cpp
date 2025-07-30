#include "ConsoleUI.h"
#include <iostream>

void ConsoleUI::displayWelcome() const {
    std::cout << "Welcome to Yahtzee!\n\n";
}

void ConsoleUI::displayDice(const std::vector<int>& dice) const {
    std::cout << "Current dice: ";
    for (int value : dice) {
        std::cout << value << " ";
    }
    std::cout << "\n\n";
}

std::vector<bool> ConsoleUI::getRerollSelection(int diceCount) const {
    std::vector<bool> selection(diceCount, false);
    std::cout << "Enter dice positions to reroll (1-5, space separated): ";
    // Parse input and set selection vector
    return selection;
}

void ConsoleUI::displayScoreOptions() const {
    std::cout << "Score Categories:\n"
        << "1. Aces\n2. Twos\n3. Threes\n4. Fours\n5. Fives\n6. Sixes\n"
        << "7. Three of a Kind\n8. Four of a Kind\n9. Full House\n"
        << "10. Small Straight\n11. Large Straight\n12. Yahtzee\n13. Chance\n";
}

int ConsoleUI::getScoringChoice() const {
    int choice;
    std::cout << "Select category to score: ";
    std::cin >> choice;
    return choice - 1; // Convert to 0-based index
}

void ConsoleUI::displayFinalScore(int score) const {
    std::cout << "\nGame Over! Final Score: " << score << "\n";
}