// Write a function that takes two parameters: a std::vector and an index. 
// If the index is out of bounds, print an error. If the index is in bounds, 
// print the value of the element.

// The following sample program should compile and produce the following results:
// // The element has value 2
// // Invalid index
// // The element has value 1.1
// // Invalid index


#include <iostream>
#include <vector>
#include <stdexcept>

// index type should be int, not std::size_t, to catch the cases when index < 0
// it works with std::size_t as expected as well - it converts it to INT_MAX which
// should be greater than the size of almost any vector. Nevertheless, it's more 
// robust to use the former approach
template <typename T>
void printElement(const std::vector<T>& vec, int index) {
    // try {
    //     T elementValue {vec.at(index)};
    //     std::cout << "The element has value " << elementValue << std::endl;
    // } 
    // catch (const std::out_of_range& orr) {
    //     std::cout << "Invalid index\n";
    //     return;
    // }
    if (index < 0 || index > vec.size() -1 ) {
        std::cout << "Invalid index\n";
    } else {
        std::cout << "The element has value " << vec[static_cast<std::size_t>(index)] << "\n";
    }
}

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}