#include "GameLogic.h"

GameLogic::GameLogic() : dice(5), rollsLeft(0) {}

void GameLogic::startNewTurn() {
    rollsLeft = 3;
    for (auto& die : dice) {
        die.roll();
    }
}

void GameLogic::rollDice(const std::vector<bool>& reroll) {
    if (rollsLeft > 0) {
        for (int i = 0; i < dice.size(); ++i) {
            if (reroll[i]) dice[i].roll();
        }
        rollsLeft--;
    }
}

bool GameLogic::scoreCategory(int category) {
    if (categoriesUsed[category]) return false;

    categoriesUsed[category] = true;

    switch (category) {
    case 0: scores["Aces"] = sumOfValues(1); break;
    case 1: scores["Twos"] = sumOfValues(2); break;
    case 2: scores["Threes"] = sumOfValues(3); break;
    case 3: scores["Fours"] = sumOfValues(4); break;
    case 4: scores["Fives"] = sumOfValues(5); break;
    case 5: scores["Sixes"] = sumOfValues(6); break;
    case 6: scores["Three of a Kind"] = checkFullHouse() ? sumAllDice() : 0; break;
    case 7: scores["Four of a Kind"] = 0; /* Implement */ break;
    case 8: scores["Full House"] = checkFullHouse() ? 25 : 0; break;
    case 9: scores["Small Straight"] = checkStraight(true) ? 30 : 0; break;
    case 10: scores["Large Straight"] = checkStraight(false) ? 40 : 0; break;
    case 11: scores["Yahtzee"] = 0; /* Implement */ break;
    case 12: scores["Chance"] = sumAllDice(); break;
    default: return false;
    }
    return true;
}

// Implement helper methods (sumOfValues, sumAllDice, checkFullHouse, checkStraight)...

