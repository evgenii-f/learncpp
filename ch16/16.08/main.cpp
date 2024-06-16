// Question #1

// Define a std::vector with the following names: "Alex”, "Betty”, "Caroline”, "Dave”, "Emily”, "Fred”, "Greg”, and
// "Holly”. Ask the user to enter a name. Use a range-based for loop to see if the name the user entered is in the array.

// Sample output:

// Enter a name: Betty
// Betty was found.
// Enter a name: Megatron
// Megatron was not found.

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

template <typename T>
bool searchInVec(const std::vector<T>& vec, const T&  val) {
    for (const T& elem : vec) {
        if (elem == val) { return true; }
    }
    return false;
}

std::string userInput() {
    using namespace std;
    cout << "Enter a name: ";
    std::string input {};
    cin >> input;
    return input;
}

int main() {
    std::vector<std::string_view> array {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg"};
    std::string nameToSeek{ userInput() };

    // By explicitly specifying std::string_view as a function template argument,
    // the compiler will implicitly convert username to `std::string_view` to match the parameter type.
    bool ifFound{ searchInVec<std::string_view>(array, nameToSeek)};

    std::cout << nameToSeek;
    if (ifFound) {
        std::cout << " was found\n";
    } else {
        std::cout << " was not found\n";
    }


    return 0;
}