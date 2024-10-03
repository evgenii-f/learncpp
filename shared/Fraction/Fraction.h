#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <numeric> // std::gcd
#include <string>


class Fraction{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    explicit Fraction(int nom=0, int den=1);

    void print() const; // outdated member function

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int val);
    friend Fraction operator*(int val, const Fraction& f1);
    friend std::ostream& operator<<(std::ostream& in, const Fraction& f);
    friend std::istream& operator>>(std::istream& out, Fraction& f);

    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
};

#endif