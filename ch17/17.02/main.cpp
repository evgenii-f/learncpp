// Initialize a std::array with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’. 
// Print the length of the array, and then use operator[], at() and std::get() to 
// print the value of the element with index 1.

// The program should print:
// The length is 5
// eee

#include "iostream"
#include "array" 

int main(){
    constexpr std::array helloArr{ 'h', 'e', 'l', 'l', 'o'};

    const std::size_t index{ 1 };
    std::cout << helloArr[index];
    std::cout << helloArr.at(index);
    std::cout << std::get<index>(helloArr);
    std::cout << std::endl;
    return 0;
}