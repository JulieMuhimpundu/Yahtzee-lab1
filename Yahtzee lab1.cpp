#include "GameLogic/GameLogic.h"
#include "UI/ConsoleUI.h"
#include <vector>
#include <iostream>

int main() {
    GameLogic game;
    ConsoleUI ui;

    ui.displayWelcome();

    // Main game loop (13 rounds for all categories)
    for (int round = 0; round < 13; ++round) {
        game.startNewTurn();
        std::cout << "\n--- Round " << (round + 1) << " ---\n";

        // Rolling phase (3 rolls max)
        for (int roll = 0; roll < 3; ++roll) {
            // Get current dice values
            std::vector<int> currentDice;
            for (const auto& die : game.getDice()) {
                currentDice.push_back(die.getValue());
            }

            ui.displayDice(currentDice);

            // Only allow reroll if not the last roll
            if (roll < 2) {
                std::cout << "Roll " << (roll + 1) << " of 3\n";
                auto reroll = ui.getRerollSelection(5);
                game.rollDice(reroll);
            }
        }

        // Scoring phase
        ui.displayScoreOptions();
        int category;
        bool validCategory = false;

        // Keep asking until valid category is selected
        while (!validCategory) {
            category = ui.getScoringChoice();
            validCategory = game.scoreCategory(category);
            if (!validCategory) {
                std::cout << "Category already used! Try again.\n";
            }
        }

        // Show current score
        std::cout << "Current score: " << game.getTotalScore() << "\n";
    }

    // Game over
    ui.displayFinalScore(game.getTotalScore());

    return 0;
}

