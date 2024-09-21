// Let’s implement our Fruit example that we talked about in our introduction to inheritance. 
// Create a Fruit base class that contains two private members: a name (std::string), 
// and a color (std::string). Create an Apple class that inherits Fruit.
// Apple should have an additional private member: fiber (double). 
// Create a Banana class that also inherits Fruit. Banana has no additional members.

// The following program should run and print:
// Apple(Red delicious, red, 4.2)
// Banana(Cavendish, yellow)
#include <iostream>
#include <string>
#include <string_view>

class Fruit {
private:
    std::string m_name{};
    std::string m_color{};
public:
    Fruit(const std::string_view name="", const std::string_view color="")
        : m_name{ name }, m_color{ color } {
    }

    const std::string& getName() const {
        return m_name;
    }

    const std::string& getColor() const {
        return m_color;
    }
};

class Banana : public Fruit {
private:
public:
    Banana(const std::string_view name="", const std::string_view color="")
        : Fruit(name, color) {
    }

    friend std::ostream& operator<<(std::ostream& out, const Banana& banana);
};

std::ostream& operator<<(std::ostream& out, const Banana& banana) {
    out << "Apple(" << banana.getName() << ", " << banana.getColor() << ")";
    return out;
}

class Apple : public Fruit {
private:
    double m_fiber{};
public:
    Apple(const std::string_view name="", const std::string_view color="", double fiber=0.0)
        : Fruit(name, color), m_fiber{ fiber } {
    }

    friend std::ostream& operator<<(std::ostream& out, const Apple& apple);
};

std::ostream& operator<<(std::ostream& out, const Apple& apple) {
    out << "Apple(" << apple.getName() << ", " << apple.getColor() << ", " << apple.m_fiber  << ")";
    return out;
}

int main()
{
	Apple a{ "Red delicious", "red", 4.2 };
	// const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}