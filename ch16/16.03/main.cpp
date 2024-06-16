// Initialize a std::vector with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’. 
// Then print the length of the array (use std::size()). Finally, print the value 
// of the element with index 1 using the subscript operator and the at() member function.

// The program should output the following:

// The array has 5 elements.
// ee

#include <vector>
#include <iostream>

int main() {
    std::vector vec {'h', 'e', 'l', 'l', 'o'};
    std::cout << "The array has " << std::size(vec) << " elements" << "\n";
    std::cout << vec[1] << vec.at(1) << "\n";

    return 0;
}