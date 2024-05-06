#include <iostream>
#include "io.h"


int readNumber() {
    std::cout << "Enter your integer: ";
    int number {};
    std::cin >> number;
    return number;
}

int computeAnswer(int x, int y) {
    return x + y;
}

void writeAnswer(int answer) {
    std::cout << "Your answer is " << answer << std::endl;
}
