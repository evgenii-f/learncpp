// Implement overloaded unary operator+ for the Point class. Unary operator+ just 
// returns its operand (it does not make negative values positive).

#include <iostream>

class Point
{
private:
    double m_x {};
    double m_y {};
    double m_z {};

public:
    Point(double x=0.0, double y=0.0, double z=0.0):
        m_x{x}, m_y{y}, m_z{z}
    {
    }

    // Convert a Point into its negative equivalent
    Point operator- () const;

    // Returns the same operant (like said in the task)
    Point operator+ () const;

    // Return true if the point is set at the origin
    bool operator! () const;

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

// Convert a Point into its negative equivalent
Point Point::operator- () const
{
    return { -m_x, -m_y, -m_z };
}

// Return true if the point is set at the origin, false otherwise
bool Point::operator! () const
{
    return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

// Returns operand (its copy)
Point Point::operator+() const {
    return  *this;
}

int main()
{
    Point point{-2, 3, -1}; // use default constructor to set to (0.0, 0.0, 0.0)

    if (!point)
        std::cout << "point is set at the origin.\n";
    else
        std::cout << "point is not set at the origin.\n";

    return 0;
}