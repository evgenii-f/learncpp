#include <iostream>
#include <stdexcept>

class Fraction
{
private:
    int m_num{ 0 };
    int m_denom{ 1 };
public:
    Fraction(int num, int denom) {
        if (denom == 0) {
            throw  std::invalid_argument("denominator cannot be zero!");
        }
        m_num = num;
        m_denom = denom;
    }

    void print() const {
        std::cout <<  m_num << '/' << m_denom << '\n';
    }

    Fraction multiply(const Fraction& f) const {
        return {m_num * f.m_num, m_denom * f.m_denom};
    }

    int getNumerator() const {
        return m_num;
    }

    int getDenominator() const {
        return m_denom;
    }
};

Fraction getFraction()
{
    int num {};
    std::cout << "Enter a value for numerator: ";
    std::cin >> num;
    int denom {};
    std::cout << "Enter a value for denominator: ";
    std::cin >> denom;
    std::cout << '\n';

    return {num, denom};
}

// Fraction multiply(const Fraction& f1, const Fraction& f2)
// {
//     return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };
// }

// void printFraction(const Fraction& f)
// {
//     std::cout << f.numerator << '/' << f.denominator << '\n';
// }

int main()
{
    Fraction f1{ getFraction() };
    Fraction f2{ getFraction() };

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).print();

    return 0;
}