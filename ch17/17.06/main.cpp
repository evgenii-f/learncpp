// Define a namespace named Animal. Inside it, define an enum containing the following 
// animals: chicken, dog, cat, elephant, duck, and snake. Also create a struct named 
// AnimalAttrs to store each animal’s name, number of legs, and the sound it makes. 
// Create a std::array of AnimalAttrs and fill out a AnimalAttrs element for each animal.

// Ask the user to enter the name of an animal. If the name does not match the name
//  of one of our animals, tell them so. Otherwise, print the AnimalAttrs for that animal. 
//  Then print the AnimalAttrs for all of the other animals that didn’t match their input.

// For example:

// Enter an animal: dog
// A dog has 4 legs and says woof.

// Here is the AnimalAttrs for the rest of the animals:
// A chicken has 2 legs and says cluck.
// A cat has 4 legs and says meow.
// A elephant has 4 legs and says pawoo.
// A duck has 2 legs and says quack.
// A snake has 0 legs and says hissss.
// Enter an animal: frog
// That animal couldn't be found.

// Here is the AnimalAttrs for the rest of the animals:
// A chicken has 2 legs and says cluck.
// A dog has 4 legs and says woof.
// A cat has 4 legs and says meow.
// A elephant has 4 legs and says pawoo.
// A duck has 2 legs and says quack.
// A snake has 0 legs and says hissss.

#include <iostream>
#include <array>
#include <string>
#include <string_view>
#include "numeric"
#include "algorithm"
#include <cassert>

std::string toLowerCase(const std::string_view str) {
    std::string out{ str };
    std::transform(out.begin(), out.end(), out.begin(),
        [](unsigned char ch){ return std::tolower(ch); }
    );
    return out;
}

namespace Animal {
    using namespace std::string_view_literals;

    enum Type{
        chicken, 
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animal_types
    };

    struct AnimalAttrs {
        static constexpr std::array names{ "chicken"sv, "dog"sv,"cat"sv, "elephant"sv, "duck"sv, "snake"sv };
        static constexpr std::array legsNumber{ 2, 4, 4, 4, 2, 0 };
        static constexpr std::array sounds{ "cluck"sv, "woof"sv, "meow"sv, "pawoo"sv, "quack"sv, "hissss"sv};

        static_assert(names.size() == max_animal_types);
        static_assert(legsNumber.size() == max_animal_types);
        static_assert(sounds.size() == max_animal_types);

        static constexpr std::string_view getAnimalName(const Type animal) {
            return names[animal];
        }

        static constexpr int getLegsNumber(const Type animal) {
            return legsNumber[animal];
        }

        static constexpr std::string_view getSound(const Type animal) {
            return sounds[animal];
        }
    };
}


std::ostream& operator<<(std::ostream& out, Animal::Type animal) {
    return out << Animal::AnimalAttrs::getAnimalName(animal);
}

std::istream& operator>>(std::istream& in, Animal::Type& animal) {
    int animalTypeNumber { -1 };
    std::string input {};
    std::getline(in >> std::ws, input);
    for(int i{ 0 }; i < Animal::max_animal_types; ++i) {
        if (Animal::AnimalAttrs::names[i] == toLowerCase(input)) {
            animal = static_cast<Animal::Type>(i);
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);
    return in;
}

void printAnimal(const Animal::Type animal) {
    assert(animal < Animal::max_animal_types && "Animal type should be < max_animal_types");
    using namespace std;
    cout << "a " << Animal::AnimalAttrs::getAnimalName(animal);
    cout << " has " <<  Animal::AnimalAttrs::getLegsNumber(animal) << " legs";
    cout << " and says " << Animal::AnimalAttrs::getSound(animal) << "\n";
}

int main() {
    Animal::Type animal{ Animal::chicken };
    std::cout << "Enter an animal: ";
    std::cin >> animal;
    if (std::cin) {
        printAnimal(animal);
    } else {
        std::cout << "That animal couldn't be found.";
    }
}