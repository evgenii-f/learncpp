// Fraction.cpp
#include "Fraction.h"

Fraction::Fraction(int nom, int den) {
    if (den == 0)
        throw std::runtime_error("Invalid denominator" + std::to_string(den));

    int grCommonDiv = std::gcd(nom, den);
    m_numerator = nom / grCommonDiv;
    m_denominator = den / grCommonDiv;
}

void Fraction::print() const {
    std::cout << m_numerator << "/" << m_denominator << "\n";
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction{f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
}

Fraction operator*(const Fraction& f1, int val) {
    return Fraction{f1.m_numerator * val, f1.m_denominator};
}

Fraction operator*(int val, const Fraction& f1) {
    return f1 * val;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.m_numerator << "/" << f.m_denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    std::string str;
    in >> str;
    std::size_t pos = str.find('/');
    if (pos != std::string::npos) {
        int nom = std::stoi(str.substr(0, pos));
        int denom = std::stoi(str.substr(pos + 1));
        f = Fraction{nom, denom};
    }
    return in;
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator;
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
    return !(f1 == f2);
}

bool operator<=(const Fraction& f1, const Fraction& f2) {
    return static_cast<double>(f1.m_numerator) / f1.m_denominator <=
                static_cast<double>(f2.m_numerator) / f2.m_denominator;
}

bool operator<(const Fraction& f1, const Fraction& f2) {
    return static_cast<double>(f1.m_numerator) / f1.m_denominator <
                static_cast<double>(f2.m_numerator) / f2.m_denominator;
}

bool operator>=(const Fraction& f1, const Fraction& f2) {
    return !(f1 < f2);
}

bool operator>(const Fraction& f1, const Fraction& f2) {
    return !(f1 <= f2);
}
