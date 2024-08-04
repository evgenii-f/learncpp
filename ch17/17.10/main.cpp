// Question #1

// Write a function to print a C-style string character by character. Use a pointer
// and pointer arithmetic to step through each character of the string and print that character. 
// Write a main function that tests the function with the string literal “Hello, world!”.


#include <iostream>

void printCString(const char cStrPtr[]) {
    for(; *cStrPtr != '\0'; cStrPtr++) {
        std::cout << *cStrPtr;
    }
} 

void printCStringBack(const char cStrPtr[]) {
    int index{ 0 };
    while (*cStrPtr != '\0') {
        index++;
        cStrPtr++;
    }
    // std::cout << "Your char is " << 
    for (; index >= 0; index--) {
        std::cout << *cStrPtr;
        cStrPtr--;
    }
}

int main() {
    char cStr1[]{ "Hello !!"};
    printCString(cStr1);
    std::cout << "\n";
    char cStr2[]{ "Hello" };
    printCStringBack(cStr1);
    std::cout << "\n";
    return 0;
}