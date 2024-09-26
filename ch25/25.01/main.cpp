#include <iostream>
#include <string_view>
#include <string>

// Our Animal/Cat/Dog example above doesn’t work like we want because a reference 
// or pointer to an Animal can’t access the derived version of speak() needed to 
// return the right value for the Cat or Dog. One way to work around this issue 
// would be to make the data returned by the speak() function accessible as part 
// of the Animal base class (much like the Animal’s name is accessible via member m_name).

// Update the Animal, Cat, and Dog classes in the lesson above by adding a new member 
// to Animal named m_speak. Initialize it appropriately. The following program should 
// work properly:

class Animal
{
protected:
    std::string m_name;
    std::string m_speak;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name, std::string_view speak="???")
        : m_name{ name }, m_speak{ speak }
    {
    }

    // To prevent slicing (covered later)
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return m_speak; }
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name, "Meow" }
    {
    }

    // std::string_view speak() const { return m_speak; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name, "Woof" }
    {
    }

    // std::string_view speak() const { return "Woof"; }
};

int main()
{
    const Cat cat{ "Fred" };
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    const Dog dog{ "Garbo" };
    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    const Animal* pAnimal{ &cat };
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    return 0;
}