#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <algorithm>
#include <limits>
#include <functional>

// 1a) Create a short program asking the user for two integer inputs and a mathematical 
// operation (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the user enters a valid operation.

const std::array operations{ '+', '-', '*', '/' };

int inputInt(std::string_view msg = ""){
    int val{};
    if (msg.length() > 0) std::cout << msg;
    std::cin >> val;
    return val;
}

char inputOp(
    std::string_view msg = "Enter your operation (+, -, *, /): ",
    std::string_view errMsg = "Wrong input!\n"
) {
    char op{'x'}; // some dummy char not in operations
    bool ifInputInvalid{ true };
    while (ifInputInvalid) {
        if (msg.length() > 0) std::cout << msg;
        std::cin >> op;
        ifInputInvalid = std::find(operations.begin(), operations.end(), op) == operations.end();
        if (ifInputInvalid) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << errMsg;
        }
    }

    return op;
}

using ArithmeticFunction = std::function<int (int, int)>;

ArithmeticFunction add = [](int x, int y) { return x + y; };
ArithmeticFunction subtract = [](int x, int y) { return x - y; };
ArithmeticFunction multiply = [](int x, int y) { return x * y; };
ArithmeticFunction divide = [](int x, int y) { return x / y; };

ArithmeticFunction getArithmeticFunc(char op) {
    switch (op) {
        case '+': return add;
        case '-': return subtract;
        case '*': return multiply;
        case '/': return divide;
        default: return nullptr;
    }
}


int getUserInput() {
    int x{ inputInt("Input x: ") };
    int y{ inputInt("Input x: ") };
    char op{ inputOp() };

    std::cout << "x = " << x << ", y = " << y;
    std::cout << ", op = " << op << std::endl;

    return 0;
}

int main() {
    int x{ inputInt("Input x: ") };
    int y{ inputInt("Input x: ") };
    char op{ inputOp() };

    ArithmeticFunction arFnc{ (* getArithmeticFunc)(op) };
    if (arFnc) {
        std::cout << x << " " << op << " " << y << " = ";
        std::cout << arFnc(x, y) << std::endl;
    }
}