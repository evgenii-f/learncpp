// Write a program that:

// - Asks the user how many names they wish to enter.
// - Dynamically allocates a std::string array.
// - Asks the user to enter each name.
// - Calls std::sort to sort the names (See 18.1 -- Sorting an array using selection 
//     sort and 17.9 -- Pointer arithmetic and subscripting)
// - Prints the sorted list of names.
// - std::string supports comparing strings via the comparison operators < and >. 
//     You don’t need to implement string comparison by hand.

// Your output should match this:

#include <array>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

int main() {
    int nElements{};
    std::cout << "Enter the number of elements you wish to enter: ";
    std::cin >> nElements;
    std::cout << std::endl;

    std::string* names{ new std::string[nElements] {} };

    std::string elementsStr{};
    std::cout << "Enter your elements separated by space:\n";
    std::getline(std::cin >> std::ws, elementsStr);

    char separator{ ' ' };
    std::size_t begin{ 0 };
    for (int i{0}; i < nElements - 1; i++) {
        std::size_t nextSepInd{ elementsStr.find(separator, begin) };
        if (nextSepInd == std::string::npos) {
            std::cout << "Error! Check if you enter the right number of elements" << std::endl;
            delete[] names;
            break;
        }
        std::string name{ elementsStr.substr(begin, nextSepInd - begin) };
        std::cout << "inserted name " << name << std::endl;
        names[i] = name;
        begin = nextSepInd + 1;
    }
    if (nElements > 0) names[nElements-1] =  elementsStr.substr(begin);

    std::sort(names, names + nElements);
    // std::sort(std::begin(names), std::end(names));
    std::cout << "Here is your sorted list:" << std::endl;
    for (int i{0}; i < nElements; i++) {
        std::cout << "Name #" << i+1 << ": " << names[i] << std::endl;
    }

    delete[] names;
    names = nullptr;
}