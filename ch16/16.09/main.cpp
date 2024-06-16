// Create a program-defined enum (inside a namespace) containing the names of the following animals: 
// chicken, dog, cat, elephant, duck, and snake. Define an array with an element for each of these animals,
//  and use an initializer list to initialize each element to hold the number of legs that animal has. 
//  Assert that the array has the correct number of initializers.

// Write a main() function that prints the number of legs an elephant has, using the enumerator.

#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

namespace Animals {
    enum AnimalTypes {
        chicken, 
        dog, 
        cat, 
        elephant, 
        duck,
        snake,
        maxAnimalTypes
    };
}

int main() {
    std::vector<int> animalLegs (Animals::maxAnimalTypes);
    assert(animalLegs.size() == Animals::maxAnimalTypes);

    animalLegs[Animals::chicken] = 2;
    animalLegs[Animals::dog] = 4;
    animalLegs[Animals::cat] = 4;
    animalLegs[Animals::elephant] = 4;
    animalLegs[Animals::duck] = 2;
    animalLegs[Animals::snake] = 0;

    std::cout << "Elephant has " << animalLegs[Animals::elephant] << " legs\n";

    return 0;
}