#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Random.h" // g++ q3.cpp -I ../../tools/  -std=c++17 -o a3.out

using input_t = std::pair<int, int>;
using vec_t = std::vector<int>;

input_t getUserInput() {
    int start{};
    std::cout << "Start where? ";
    std::cin >> start;

    int n{};
    std::cout << "How many? ";
    std::cin >> n;

    return {start, n};
}

vec_t getVector(int start, int n) {
    vec_t res{};
    for (int i{0}; i < n; i++) res.push_back(start+i);
    return res;
}

// auto modifyVal {
//     [](int pow, int multiplier) {}
// }

auto printVec {
    [](const vec_t& vec) {
        for (const auto& el : vec) std::cout << el << " ";
        std::cout << std::endl;
    }
};

bool findAndRemove(vec_t& vec, int guess){
    auto found{ std::find(vec.begin(), vec.end(), guess) };

    if (found == vec.end()) return false;
    
    vec.erase(found);
    return true;
}

int takeTurn(vec_t& vec, int guess, int factor) {
    std::cout <<  "Do you know what each number is after multiplying it by " << factor << "?\n";
    std::cin >> guess;
    
    return guess;
}

int findClosestEl(vec_t numbers, int guess) {
    return *std::min_element(numbers.begin(), numbers.end(), [=](auto a, auto b){
        return std::abs(a - guess) < std::abs(b - guess);
    });
}

int main() {
    input_t input{ getUserInput() };
    vec_t numbers{ getVector(input.first, input.second) };
    int factor{ Random::get(2, 4) };

    std::for_each(numbers.begin(), numbers.end(), [factor](int& n) {
        n *= n * factor;
    });

    std::cout << "I generated " << numbers.size() <<  " square numbers.\n";

    bool ifGuessRight{ true };
    while (ifGuessRight && numbers.size() > 0) {
        int guess{ takeTurn(numbers, guess, factor) };
        ifGuessRight = findAndRemove(numbers, guess);
        if (ifGuessRight) {
            std::string s{
                numbers.size() > 0
                ? "Nice! " + std::to_string(numbers.size()) + " number(s) left.\n"
                : "Nice! You found all numbers, good job!\n"
            };
            std::cout << s;
        } else {
            int closestElement{ findClosestEl(numbers, guess) };
            std::cout <<  guess << " is wrong! Try " << closestElement << " next time\n";
        }
    }    




    return 0;
}
