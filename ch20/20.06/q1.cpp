// Create a struct Student that stores the name and points of a student. 
// Create an array of students and use std::max_element to find the student with the most points, 
// then print that student's name. 
// std::max_element takes the begin and end of a list, and a function that takes 2 parameters 
// and returns true if the first argument is less than the second.

// Given the following array
// std::array<Student, 8> arr{
//   { { "Albert", 3 },
//     { "Ben", 5 },
//     { "Christine", 2 },
//     { "Dan", 8 }, // Dan has the most points (8).
//     { "Enchilada", 4 },
//     { "Francis", 1 },
//     { "Greg", 3 },
//     { "Hagrid", 5 } }
// };

// your program should print

// Dan is the best student

#include <array>
#include <string>
#include <iostream>
#include <string_view>

struct Student {
    std::string_view name;
    int points;
};

auto studentWorse{
    [](const Student& s1, const Student& s2) {
        return s1.points < s2.points;
    }
};

int main() {
    std::array<Student, 8> arr{
    { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    Student* bestStudent{ std::max_element(arr.begin(), arr.end(), studentWorse) };

    std::cout << bestStudent -> name << " is the best student.\n";


    return 0;
}