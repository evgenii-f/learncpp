#include <iostream>
#include <string>

int main() {
    std::string name {};
    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, name);

    int age {};
    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "So, people call you " << name << ", and you are " << age << " years old." << std::endl;
}