#include <iostream>
#include <string>


enum class Animal {
    pig, 
    chicken, 
    goat, 
    cat, 
    dog, 
    duck
};

constexpr std::string_view getAnimalName(Animal animal) {
    switch (animal) {
        case Animal::pig: {return std::string_view("pig");}
        case Animal::chicken: {return std::string_view("chicken");}
        case Animal::goat: {return std::string_view("goat");}
        case Animal::cat: {return std::string_view("cat");}
        case Animal::dog: {return std::string_view("dog");}
        case Animal::duck: {return std::string_view("duck");}
        default: {return std::string_view("unknow animal");}
    }
}

int getNumberOfLegs(Animal animal) {
        switch (animal) {
        case Animal::pig: 
        case Animal::goat: 
        case Animal::cat: 
        case Animal::dog: { return 4; }
        case Animal::chicken: 
        case Animal::duck: { return 2; }
        default: { return -1; }
    }
}

int main() {
    Animal cat {Animal::cat};
    Animal pig {Animal::pig};
    Animal chicken {Animal::chicken};

    std::cout << "Animal " << getAnimalName(cat) << " has " << getNumberOfLegs(cat) << " legs\n";
    std::cout << "Animal " << getAnimalName(pig) << " has " << getNumberOfLegs(pig) << " legs\n";
    std::cout << "Animal " << getAnimalName(chicken) << " has " << getNumberOfLegs(chicken) << " legs\n";

    return 0;
}