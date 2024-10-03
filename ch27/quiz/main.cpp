//Implementation of the exception throwing in the Fraction constructor when denominator = 0
// is in the implementation file /shared/Fraction/Fraction.cpp
#include <iostream>
#include <exception>
#include <utility>
// g++ main.cpp ../../shared/Fraction/Fraction.cpp -std=c++20
#include "../../shared/Fraction/Fraction.h"

std::pair<int, int> getUserInput() {
    int x {};
    int y {};
    std::cout << "Enter the numerator: ";
    std::cin >> x;

    std::cout << "Enter the denominator: ";
    std::cin >> y;

    return {x, y};
}


int main() {
    auto userInput{ getUserInput() };
    Fraction f{};
    try {
        f = Fraction(userInput.first, userInput.second);
    } catch (const std::exception& e) {
        std::cout << "Caught exception " << e.what() << std::endl;
    }
    return 0;
}