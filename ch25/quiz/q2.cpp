#include <iostream>
#include <memory>

// 2a) Create an abstract class named Shape. This class should have three functions: a pure virtual print function that 
// takes and returns a std::ostream&, an overloaded operator<< and an empty virtual destructor.

class Shape {
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape);

    virtual ~Shape() {
    };
};

std::ostream& operator<<(std::ostream& out, const Shape& shape) {
    return shape.print(out);
}

// 2b) Derive two classes from Shape: a Triangle, and a Circle. The Triangle should have 3 Points as members. 
// The Circle should have one center Point, and an integer radius. 
// Overload the print() function so the following program runs and prints:

// Circle(Point(1, 2), radius 7)
// Triangle(Point(1, 2), Point(3, 4), Point(5, 6))

// let's create a struct Point

struct Point {
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "Point(" << p.x << ", " << p.y << ")";
    return out;
}

class Circle : public Shape {
protected:
    Point m_center{};
    int m_radius{};

public:
    Circle(const Point& center, int radius)
        : m_center{ center }, m_radius{ radius } {
    }

    int getRadius() const {
        return m_radius;
    }

    std::ostream& print(std::ostream& out) const override {
        out << "Circle(" << m_center << ", radius " << m_radius << ")";
        return out;
    }
};


class Triangle : public Shape {
protected:
    Point m_p1{};
    Point m_p2{};
    Point m_p3{};

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : m_p1{ p1 }, m_p2{ p2 }, m_p3{ p3 } {
    }

    std::ostream& print(std::ostream& out) const override {
        out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
        return out;
    }
};



// int main()
// {
//     std::cout << Point{ 1, 2 } << std::endl;

//     Circle c{ Point{ 1, 2 }, 7 };
//     std::cout << c << '\n';

//     Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
//     std::cout << t << '\n';


//     return 0;
// }

// 2c) Given the above classes (Point, Shape, Circle, and Triangle), finish the following program, which should print:
// Circle(Point(1, 2), radius 7)
// Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
// Circle(Point(7, 8), radius 3)
// The largest radius is: 7



int getLargestRadius(const std::vector<Shape*>& shapes_v) {
    int radius{ -1 };
    for (const auto* shapePtr : shapes_v) {
        const Circle* circleP{ dynamic_cast<const Circle*>(shapePtr) };
        if (circleP)
            radius = std::max(radius, circleP->getRadius());
    }

    return radius;
}

// int main()
// {
// 	std::vector<Shape*> v{
//         new Circle{Point{ 1, 2 }, 7},
//         new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
//         new Circle{Point{ 7, 8 }, 3}
// 	};

// 	// print each shape in vector v on its own line here
//     for (const auto* shapePtr : v)
//         std::cout << *shapePtr << '\n';

// 	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

// 	// delete each element in the vector here
//     for (const auto* p : v)
//         delete p;

// 	return 0;
// }

// 2d) Extra credit: Update the prior solution to use a std::vector<std::unique_ptr<Shape>>. 
// Remember that std::unique_ptr is not copyable.

using uniqueShapePtr_t = std::unique_ptr<Shape>;

int getLargestRadius(const std::vector<uniqueShapePtr_t>& shapes_v) {
    int radius{ -1 };
    for (const auto& shapePtr : shapes_v) {
        const Circle* circleP{ dynamic_cast<const Circle*>(shapePtr.get()) };
        if (circleP)
            radius = std::max(radius, circleP->getRadius());
    }

    return radius;
}

int main()
{
    std::vector<uniqueShapePtr_t> v; 
    v.emplace_back( std::make_unique<Circle>(Circle{Point{ 1, 2 }, 7}) );
    v.emplace_back( std::make_unique<Triangle>(Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }}) );
    v.emplace_back( std::make_unique<Circle>(Circle{Point{ 7, 8 }, 3}) );

	// print each shape in vector v on its own line here
    for (const auto& shapePtr : v)
        std::cout << *shapePtr << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function


	return 0;
}