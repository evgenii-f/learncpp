// Create a struct to hold a fraction. The struct should have an integer numerator 
// and an integer denominator member.
// Write a function to read in a Fraction from the user, and use it to read-in two fraction objects. 
// Write another function to multiply two Fractions together
// and return the result as a Fraction (you don’t need to reduce the fraction). 
// Write another function that prints a fraction.

// Enter a value for the numerator: 1
// Enter a value for the denominator: 2

// Enter a value for the numerator: 3
// Enter a value for the denominator: 4

// Your fractions multiplied together: 3/8

// When multiplying two fractions together, the resulting numerator is the product 
// of the two numerators, and the resulting denominator is the product of the two denominators.

#include <iostream>

struct Fraction {
    int numerator {};
    int denominator {};
};

Fraction inputFraction() {
    using namespace std;

    int numerator {};
    int denominator {};

    cout << "Enter a value for the numerator: ";
    cin >> numerator;

    cout << "Enter a value for the denominator: ";
    cin >> denominator;

    return {numerator, denominator};
}

void printFraction(const Fraction& fract) {
    std::cout << "Your fraction is " << fract.numerator << "/" << fract.denominator << "\n";
}

std::ostream& operator<< (std::ostream& out, const Fraction& fract) {
    out << fract.numerator << "/" << fract.denominator;
    return out;
}

constexpr Fraction multiplyFractions(const Fraction& fract1, const Fraction& fract2) {
    return {
        fract1.numerator * fract2.numerator,
        fract1.denominator * fract2.denominator
    };
}

int main() {
    Fraction fract1 { inputFraction() };
    std::cout << "\n";
    Fraction fract2 { inputFraction() };
    std::cout << "\n";
    Fraction product { multiplyFractions(fract1, fract2)};
    std::cout << fract1 << " x " << fract2 << " = " << product << "\n";
};

