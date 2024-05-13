// Task 1
// Write a class named Ball. Ball should have two private member variables, one to hold a color (default value: black),
//  and one to hold a radius (default value: 10.0). Add 4 constructors, one to handle each case below (see the given main)

// The program should produce the following result:

// Ball(black, 10)
// Ball(blue, 10)
// Ball(black, 20)
// Ball(blue, 20)

// Task 2
// Reduce the number of constructors in the above program by using default arguments and delegating constructors.
#include <string>
#include <iostream>

class Ball;

void printBall(const Ball* ball);

class Ball{
private:
    std::string m_color {"black"};
    double m_rad {};

public:
    // how it was after task #1
    // Ball() { printBall(this); }

    // Ball(const std::string_view& color)
    //     : m_color {color}
    // { printBall(this); }

    // Ball(double rad)
    //     : m_rad {rad}
    // { printBall(this); }

    // Ball(const std::string_view& color, double rad)
    //     : m_color {color}, m_rad {rad}
    // { printBall(this); }

    Ball(const std::string_view& color="black", double rad = .0)
        : m_color {color}, m_rad {rad}
    { printBall(this); } 

    Ball(double rad)
        : m_rad {rad}
    { printBall(this); }

    std::string_view color() const {
        return m_color;
    }

    double rad() const {
        return m_rad;
    }

};

// this is not the best implementation because of the pointer. However, I wanted
// to use this for the sake of training
void printBall(const Ball* ball) {
    std::cout << "Ball(" << ball->color() << ", " << ball->rad() << ")\n";
}


int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}