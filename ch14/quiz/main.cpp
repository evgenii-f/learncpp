// a) Write a class named Point2d. Point2d should contain two member variables of 
// type double: m_x, and m_y, both defaulted to 0.0.
// Provide a constructor and a print() function.
// The following program should run (see the main)

#include <iostream>
#include <cmath>

//my code
class Point2d {
private:
    double m_x {};
    double m_y {};

public:
    Point2d() = default;

    Point2d(double x, double y)
        : m_x {x}, m_y{y}
    {}

    void print() const {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    double distanceTo(const Point2d& p){
        return std::sqrt(
            (m_x - p.m_x) * (m_x - p.m_x) +
            (m_y - p.m_y) * (m_y - p.m_y)
        );
    }
};

// the main was given
// This should print:
// Point2d(0, 0)
// Point2d(3, 4)

// b) Now add a member function named distanceTo() that takes another Point2d 
// as a parameter, and calculates the distance between them.

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    // for question2
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
