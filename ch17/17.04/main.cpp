// Question #1

// Define a struct named Item that contains two members: std::string_view name and int gold. 
//Define a std::array and initialize it with 4 Item objects, explicitly specifying the 
//element type for each initializer. Assume you may add additional elements to the std::array later.

// The program should print the following:

// A sword costs 5 gold.
// A dagger costs 3 gold.
// A club costs 2 gold.
// A spear costs 7 gold.

// Question #2

// Update your solution to quiz 1 to not explicitly specify the element type for each initializer.

#include <string_view>
#include "array"
#include <iostream>

struct Item {
    std::string_view name{ "???" };
    int gold{ };
};

void printItem(const Item& item) {
    std::cout << "A " << item.name << " costs " << item.gold << " gold\n";
}

int main() {
    using namespace std::string_view_literals;

    // q1
    // constexpr std::array items {
    //     Item{"sword"sv, 5},
    //     Item{"dagger"sv, 3},
    //     Item{"club"sv, 2},
    //     Item{"spear"sv, 7},
    // };

    //q2
    constexpr std::array<Item, 4> items {{
        {"sword"sv, 5},
        {"dagger"sv, 3},
        {"club"sv, 2},
        {"spear"sv, 7},
    }};

    for (const Item& el : items) {
        printItem(el);
    }
    
    return 0;
}