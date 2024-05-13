// Write a class named Ball. Ball should have two private member variables, one to 
// hold a color, and one to hold a radius. Also write a function to print out the color and radius of the ball.

// The following sample program should compile (see the given main)
#include <iostream>
#include <string>

class Ball {
private:
    std::string m_color {};
    double m_rad {};

public:
    Ball(const std::string_view& color, double rad) :
        m_color{color}, m_rad{rad}
    {}

    const std::string& getColor() const {
        return m_color;
    }

    double getRad() const {
        return m_rad;
    }
};

void print(const Ball& ball) {
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRad() << ")\n";
}

int main()
{
	Ball blue{ "blue", 10.0 };
	print(blue);

	Ball red{ "red", 12.0 };
	print(red);

	return 0;
}