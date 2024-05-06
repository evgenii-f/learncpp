#include <iostream>
#include <string>

const std::string& getProgramNameWrong() {
    return std::string {"Program Huiram"};
}

const std::string& getProgramNameRight() {
    static std::string name {"Program Huiram"};
    return name;
}

int main() {
    // here we have a dangling reference situation
    std::cout << "Program name: " << getProgramNameWrong() << "\n";
    // here it should be correct
    std::cout << "Program name: " << getProgramNameRight() << "\n";
    return 0;
}