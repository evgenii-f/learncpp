// a) Write an Apple class and a Banana class that are derived from a common Fruit class. 
// Fruit should have two members: a name and a color.

// The following program should run and print:
// My apple is red.
// My banana is yellow.
#include <iostream>
#include <string>
#include <string_view>

class Fruit {
private:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit(const std::string_view name="???", const std::string_view color="no color")
        : m_name{ name }, m_color{ color } {
    }

    const std::string& getName() const {
        return m_name;
    }

    const std::string& getColor() const {
        return m_color;
    }
};

class Apple : public Fruit{
// The previous constructor we used for Apple had a fixed name ("apple").
// We need a new constructor for GrannySmith to use to set the name of the fruit
protected: // protected so only derived classes can access
	Apple(std::string_view name, std::string_view color)
		: Fruit{ name, color }
	{
	}

public:
    Apple(std::string_view color="red")
        : Fruit("apple", color) {
    }
};

class Banana : public Fruit{
public:
    Banana(std::string_view color="yellow")
        : Fruit("banana", color) {
    }
};

// int main()
// {
// 	Apple a{ "red" };
// 	Banana b{};

// 	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
// 	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

// 	return 0;
// }

// b) Add a new class to the previous program called GrannySmith that inherits from Apple.

// The following program should run and print:
// My apple is red.
// My banana is yellow.
// My granny smith apple is green.

class GrannySmith : public Apple {
public:
    GrannySmith() : Apple( "granny smith apple", "green" ) {
    }
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}