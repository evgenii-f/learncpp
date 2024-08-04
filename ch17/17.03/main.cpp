// Complete the following program:
// When run, it should print:

// The array (1, 4, 9, 16) has length 4
// The array (h, e, l, l, o) has length 5

#include <array>
#include <iostream>

//my part
template <typename T, std::size_t N>
constexpr void printArray(const std::array<T, N>& arr){
    std::cout << "The array (";
    for (std::size_t index{ 0 }; index < N-1; ++index) {
        std::cout << arr[index] << ", ";
    }
    std::cout << arr[N-1];
    std::cout << ") has length " << N << "\n";
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
