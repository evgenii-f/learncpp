// Let’s say you’re writing a game where the player can hold 3 Type of items: health potions, torch, and arrows.

////// step 1 //////
// Define an unscoped enum in a namespace to identify the different Type of items. 
// Define an std::vector to store the number of each item Type the player is carrying.
// The player should start with 1 health potion, 5 torch, and 10 arrows.
// Assert to make sure the array has the correct number of initializers.
// Hint: Define a count enumerator and use it inside the assert.
//
// The program should output the following:
// You have 16 total items

////// step 2 //////
// Modify your program from the prior step so it now outputs:
//
// You have 1 health potion
// You have 5 torch
// You have 10 arrows
// You have 16 total items
// Use a loop to print out the number of items and the item names for each inventory 
// item. Handle proper pluralization of the names.


#include "iostream"
#include "vector"
#include "cassert"
#include <numeric>
#include <utility>

namespace Items {
    enum Type{
        healthPotion,
        torch,
        arrow,
        max_number
    };
}

std::string getItemName(Items::Type type, bool ifOneItem){
    switch(type) {
        case Items::healthPotion: return ifOneItem ? "health potion" :  "health potions";
        case Items::torch: return ifOneItem ? "torch" : "torches";
        case Items::arrow: return ifOneItem ? "arrow" : "arrows";
        default: return "???";
    }
}

void printInventory(const std::vector<int>& inventory){
    using namespace std;
    assert(std::size(inventory) == Items::max_number);
    for (std::size_t itemIndex{ 0 }; itemIndex < std::size(inventory); itemIndex++) {
        int nItems{ inventory[itemIndex]};
        Items::Type itemType{ static_cast<Items::Type>(itemIndex) };
        cout << "You have " << nItems << " " << getItemName(itemType, nItems==1) << "\n";
    }
    cout << "You have " << std::accumulate(inventory.begin(), inventory.end(), 0)
         << " total items\n";
}

int main() {
    std::vector<int> inventory( Items::max_number );
    assert(inventory.size() == Items::max_number );
    inventory[Items::healthPotion] = 1;
    inventory[Items::torch] = 5;
    inventory[Items::arrow] = 10;

    printInventory(inventory);
}

