// Take the Fraction class we wrote in the previous quiz (listed below) and 
// add an overloaded operator<< and operator>> to it.

// The following program should compile:
// and print
// Enter fraction 1: 2/3
// Enter fraction 2: 3/8
// 2/3 * 3/8 is 1/4

#include <iostream>
#include <numeric>
#include  "../../shared/Fraction/Fraction.h" 

// this implementation is moved to ../../shared!

// class Fraction{
// private:
//     int m_nom{ 0 };
//     int m_den{ 1 };

// public:g+
//     explicit Fraction(int nom = 0, int den = 1)  {
//         int grCommonDiv{ std::gcd(nom, den) };
//         m_nom = nom / grCommonDiv;
//         m_den = den / grCommonDiv;
//     }

//     void print() const {
//         std::cout << m_nom << "/" << m_den << "\n";
//     }

//     friend Fraction operator*(const Fraction& f1, const Fraction& f2) {
//         return Fraction{ f1.m_nom * f2.m_nom, f1.m_den * f2.m_den};
//     }

//     friend Fraction operator*(const Fraction& f1, int val) {
//         return Fraction{ f1.m_nom * val, f1.m_den };
//     }

//     friend Fraction operator*(int val, const Fraction& f1) {
//         return f1 * val;
//     }

//     friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
//         out << f.m_nom << "/" << f.m_den;
//         return out;
//     }

//     friend std::istream& operator>>(std::istream& in, Fraction& f) {
//         std::string str{};
//         in >> str;
//         std::size_t pos { str.find('/') };
//         if (pos != std::string::npos) {
//             int nom{ std::stoi(str.substr(0, pos)) };
//             int denom{ std::stoi(str.substr(pos+1)) };
//             f = Fraction{ nom, denom };
//         }

//         return in;
//     }

// };

int main()
{
	Fraction f1{1, 2};
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2{};
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}

