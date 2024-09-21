// A) What are the top-level things that your program needs to do? Here are a few to get you started:

// Board things:

// Display the game board
// Move a tile according to the user command
// Check if the game is finished
// Track the position of the emtpy tile
// Randomize the starting positions

// User things:
// Get commands from user
// Make checkup if the move is possible
// Allow quit

// helpers:

// randomizatorPositions
// winCheck
// BoardClass
// ViewClass

// userInputCheck
// userInputModule

#include "Board.h"
#include <iostream>
#include <format>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace Game {
    enum Input {
        Up = 'w',
        Left = 'a',
        Down = 's',
        Right = 'd',
        Quit = 'q'
    };

    bool isValidInput(char c) {
        return c == Up || c == Left || c == Down || c == Right || c == Quit;
    }

    Input getUserInput() {
        char choice{};
        while (!isValidInput(choice)) {
            std::cout << "Enter command (w - up, a - left, s - down, d - right, q - quit): ";
            std::cin >> choice;
        }
        return static_cast<Input>(choice);
    }

};

int main() {
    Board<3> b {};
    std::cout << b << '\n';
    Game::Input input{ Game::getUserInput() };
    std::cout << input;
}

