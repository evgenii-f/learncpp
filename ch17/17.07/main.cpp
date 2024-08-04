//// q1
// Convert the following std::array definition to an equivalent constexpr C-style array definition:
// constexpr std::array<int, 3> a{}; // allocate 3 ints

////q3
// A “perfect square” is a natural number whose square root is an integer.
// We can make perfect squares by multiplying a natural number (including zero) by itself.
// The first 4 perfect squares are: 0, 1, 4, 9.

// Use a global constexpr C-style array to hold the perfect squares between 0 and 9 (inclusive). 
// Repeatedly ask the user to enter a single digit integer, or -1 to quit. 
// Print whether the digit the user entered is a perfect square.

// The output should match the following:

// Enter a single digit integer, or -1 to quit: 4
// 4 is a perfect square

// Enter a single digit integer, or -1 to quit: 5
// 5 is not a perfect square

// Enter a single digit integer, or -1 to quit: -1
// Bye
// Hints: Use a range-based for loop to traverse the C-style array to look for a match.

#include <iostream>
#include <limits>

int getUserInput() {
    int userInput{ 10 };
    while (true) {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> userInput;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (
            (userInput > 0 && userInput < 10) ||
            userInput == -1
        ) {
            return userInput;
        }

        std::cout << "That wasn't a valid input.  Try again.\n";
    }
}

int main() {
    //q1
    constexpr int a[3] {};
    std::cout << a[2] << std::endl;
    //

    //q3
    //
    int perfectSquares[]{ 0, 1, 4, 9 };
    int userInput{ getUserInput() };
    if (userInput == -1) {
        std::cout << "Bye\n";
        return 0;
    }

    auto ifPerfectSquare{ std::find(std::begin(perfectSquares),std::end(perfectSquares), userInput) };
    std::cout << ifPerfectSquare << std::endl;
    if (ifPerfectSquare) {
        std::cout << userInput << " is a perfect square\n";
    } else {
        std::cout << userInput << " is a perfect square\n";
    }

    return 0;
}