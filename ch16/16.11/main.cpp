// Write a program that pushes and pops values, and outputs the following sequence:

//        (Stack: empty)
// Push 1 (Stack: 1)
// Push 2 (Stack: 1 2)
// Push 3 (Stack: 1 2 3)
// Pop    (Stack: 1 2)
// Push 4 (Stack: 1 2 4)
// Pop    (Stack: 1 2)
// Pop    (Stack: 1)
// Pop    (Stack: empty)

#include <iostream>
#include <vector>

template <typename T>
void printStack(const std::vector<T>& stackArr) {
    std::cout << "( Stack: ";
    if (stackArr.size() == 0) {
        std::cout << "empty ";
    }

    for (const auto& elem : stackArr) {
        std::cout << elem << " ";
    }

    std::cout << ")\n";
}


int main() {
    std::vector<int> stackVec{ };
    
    std::cout << "\t";
    printStack(stackVec);

    int pushCounter{ 0 };
    for (auto val : {1, 2, 3}) {
        stackVec.push_back(val);
        std::cout << "Push " << ++pushCounter << "\t";
        printStack(stackVec);
    }

    stackVec.pop_back();
    std::cout << "Pop " << "\t";
    printStack(stackVec);

    stackVec.push_back(4);
    std::cout << "Push " << ++pushCounter << "\t";
    printStack(stackVec);

    while (stackVec.size() != 0) {
        stackVec.pop_back();
        std::cout << "Pop " << "\t";
        printStack(stackVec);
    }

    std::cout << std::endl;
    std::cout << sizeof(std::vector<int>);

    return 0;
}

