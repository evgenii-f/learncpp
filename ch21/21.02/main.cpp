// a) Write a class named Fraction that has an integer numerator and denominator 
// member. Write a print() function that prints out the fraction.

// b) Add overloaded multiplication operators to handle multiplication between a 
// Fraction and integer, and between two Fractions. Use the friend function method.


// e) Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to
//  the lowest terms. We can reduce any given fraction to lowest terms by finding 
//  the greatest common divisor (GCD) between the numerator and denominator, and 
//  then dividing both the numerator and denominator by the GCD.

// std::gcd() was added to the standard library in C++17 (in the <numeric> header).

#include <iostream>
#include <numeric>

class Fraction{
private:
    int m_nom{ 0 };
    int m_den{ 1 };

public:
    explicit Fraction(int nom, int den)  {
        int grCommonDiv{ std::gcd(nom, den) };
        m_nom = nom / grCommonDiv;
        m_den = den / grCommonDiv;
    }

    void print() const {
        std::cout << m_nom << "/" << m_den << "\n";
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2) {
        return Fraction{ f1.m_nom * f2.m_nom, f1.m_den * f2.m_den};
    }

    friend Fraction operator*(const Fraction& f1, int val) {
        return Fraction{ f1.m_nom * val, f1.m_den };
    }

    friend Fraction operator*(int val, const Fraction& f1) {
        return f1 * val;
    }

};


// a) The following code should compile and print
// 1/4
// 1/2
// int main()
// {
//     Fraction f1{ 1, 4};
//     f1.print();

//     Fraction f2{ 1, 2 };
//     f2.print();

//     return 0;
// }

// b) The following code should compile and print:
// 2/5
// 3/8
// 6/40
// 4/5
// 6/8
// 6/24

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    return 0;
}
