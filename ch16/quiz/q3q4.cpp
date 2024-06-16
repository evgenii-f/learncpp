////// question 3 //////
// Write a function that takes a std::vector, returns a std::pair containing the indices
//  of the elements with the min and max values in the array. The documentation 
// for std::pair can be found here. Call the function on the following two vectors:
//
// std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
// std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
// The program should output the following:
// With array ( 3, 8, 2, 5, 7, 8, 3 ):
// The min element has index 2 and value 2
// The max element has index 1 and value 8
//
// With array ( 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 ):
// The min element has index 4 and value 1.2
// The max element has index 5 and value 8.8


////// question 3 //////
// Modify the prior program so that the user can enter as many integers as they like.
//  Stop accepting input when the user enters -1.

// Print the vector and find the min and max elements.

// When run with the input 3 8 5 2 3 7 -1, the program should produce the following output:

// Enter numbers to add (use -1 to stop): 3 8 5 2 3 7 -1
// With array ( 3, 8, 5, 2, 3, 7 ):
// The min element has index 3 and value 2
// The max element has index 1 and value 8
// Do something reasonable when the user enters -1 as the first input.

#include "iostream"
#include "vector"
#include <utility>
#include "limits"

template <typename T>
void printVector(const std::vector<T> vec){
    using namespace std;
    cout << "[ ";
    for (const auto& el : vec) {
        cout << el << " ";
    }
    cout << "]\n";
}

template <typename T>
std::pair<int, int>findMinMax(const std::vector<T>& vec){
    if (vec.size() == 0) { return std::pair(-1, -1); };
    int maxIndex{ 0 };
    int minIndex{ 0 };
    for (std::size_t index{ 0 }; index < vec.size(); index++) {
        if (vec[maxIndex] > vec[index]) { maxIndex = index; };
        if (vec[minIndex] < vec[index]) { minIndex = index; };
    }
    return std::pair(minIndex, maxIndex);
}

template<typename T>
void printMinMax(const std::vector<T>& vec){
    std::cout << "Your vector is ";
    printVector(vec);
    std::pair minMaxIndices{ findMinMax(vec) };
    auto minIndex{ minMaxIndices.first };
    auto maxIndex{ minMaxIndices.second };
    if (minIndex < 0 || maxIndex < 0) {
        std::cout << "No max or min found. Is your vector empty?\n";
    } else {
        std::cout << "The min element has index " << minIndex << " and value " << vec[minIndex] << "\n";
        std::cout << "The max element has index " << maxIndex << " and value " << vec[maxIndex] << "\n";
    }
}

std::vector<int> inputVector(){
    using namespace std;
    vector<int> vec {};
    int inputValue {};
    cout << "Enter numbers to add (use -1 to stop): ";
    while (true) {
        cin >> inputValue;
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
        } else if(inputValue == -1) {
            return vec;
        } 
        else {
            vec.push_back(inputValue);
        }
    }
}


int main() {
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    std::vector<int> v3 {};

    printMinMax(v1);
    std::cout << "\n";
    printMinMax(v2);
    std::cout << "\n";
    printMinMax(v3);
    std::cout << "\n";

    std::cout << "Now let's check your vector...\n";
    std::vector myVec{ inputVector() };
    printMinMax(myVec);
}