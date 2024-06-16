// Write a function template to find the largest value in a std::vector. 
// If the vector is empty, return the default value for the element type.

// The following code should execute (see the provided main):

// And print the following result:

// 92
// -13
// 0

#include <vector>
#include <iostream>

template <typename T>
T findMax(const std::vector<T>& vec) {
    if (vec.size() == 0) { return T {}; }
    T maxVal {vec[0]};
    for (const auto& elem : vec) {
        if (elem > maxVal) { maxVal = elem; }
    }
    return maxVal;
}

int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    return 0;
}
