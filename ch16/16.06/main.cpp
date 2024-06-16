// Question #1
// Write a short program that prints the elements of the following vector to the screen using a loop:

// Question #2
// Update your code for the prior quiz solution so that the following program compiles and has the same output:

// Question #3

// Given the solution for quiz 2, do the following:

// Ask the user for a value between 1 and 9. If the user does not enter a value between 1 and 9, repeatedly ask for an 
// integer value until they do. If the user enters a number followed by extraneous input, ignore the extraneous input.

// Print the array.

// Write a function template to search the array for the value that the user entered. If the value is in the array, 
//return the index of that element. If the value is not in the array, return an appropriate value.
// If the value was found, print the value and index. If the value was not found, print the value and that it was not found.
// We cover how to handle invalid input in lesson 9.5 -- std::cin and handling invalid input.
// Here are two sample runs of this program:

// Enter a number between 1 and 9: d
// Enter a number between 1 and 9: 6
// 4 6 7 3 8 2 1 9
// The number 6 has index 1

// Enter a number between 1 and 9: 5
// 4 6 7 3 8 2 1 9
// The number 5 was not found


#include <iostream>
#include <vector>
#include <limits> // for std::numeric_limits


// Q2 answer
template <typename T>
void printArray(const std::vector<T> vec){
    using namespace std;
    size_t length = vec.size();
    
    cout << "[ ";
    for (size_t i{ 0 }; i < length - 1; ++i) {
        cout << vec[i] << ", ";
    }

    if (length != 0) {
    cout << vec[length - 1];
    }
    
    cout << " ]\n";
}

// Q3 answer

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int inputInt1To9() {
    using namespace std;
    while (true) {
        cout << "Enter a number between 1 and 9: ";
        int input {};
        cin >> input;
        if (!cin || input > 9 || input < 1) {
            cin.clear();
            ignoreLine();
            continue;
        }

        ignoreLine();
        return input;
    }
}

template <typename T>
int search(const std::vector<T>& vec, const T& val) {
    for (std::size_t index{ 0 }; index < vec.size(); ++index) {
        if (vec[index] == val) {
            return static_cast<int>(index);
        }
    }
    return -1;
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    // Q1: Add your code here
    int sum{ 0 };
    for (size_t i{ 0 }; i < arr.size(); ++i) {
        sum += arr[i];
    }

    std::cout << "the sum is " << sum << "\n";

    // Q2: use function template to print array
    // printArray(arr);

    //Q3
    int input{ inputInt1To9() };
    printArray(arr);

    auto foundIndex{ search(arr, input) };
    if (foundIndex < 0) {
        std::cout << "The number " << input << " was not found.\n";
    } else {
        std::cout << "The number " << input << " has index " << foundIndex << ".\n";
    }
    
    return 0;
}