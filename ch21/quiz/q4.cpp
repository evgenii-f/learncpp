// > Step #2
// A floating point number is a number with a decimal where the number of digits after 
// the decimal can be variable. A fixed point number is a number with a fractional 
// component where the number of digits in the fractional portion is fixed.

// In this quiz, we’re going to write a class to implement a fixed point number with 
// two fractional digits (e.g. 12.34, 3.00, or 1278.99). Assume that the range 
// of the class should be -32768.99 to 32767.99, that the fractional component should
//  hold any two digits, that we don’t want precision errors, and that we want to conserve space.

#include <cassert>
#include <iostream>
#include <cstdint>
#include <cmath>

using base_t = std::int16_t;
using decimal_t = std::int8_t;

class FixedPoint2 {
private:
    base_t m_base{ 0 };
    decimal_t m_decimal{ 0 };
public:

    FixedPoint2(base_t i = 0, decimal_t f = 0) {
        int sign { i >= 0 && f >= 0 ? 1 : -1 };
        m_base = sign * std::abs(i);
        m_decimal = sign * std::abs(f);
        
        m_base += m_decimal / 100;
        m_decimal = m_decimal % 100;
    }

    FixedPoint2(double num) {
        int sign { num >= 0 ? 1 : -1 };
        m_base =  static_cast<base_t>(
            std::floor(std::abs(num))
        );
        m_decimal = static_cast<decimal_t>(
            (std::abs(num) - m_base) * 100  + 0.5
        );

        m_base *= sign;
        m_decimal *= sign;

        // their solution, looks better
        // FixedPoint2(
		// 	static_cast<std::int16_t>(std::trunc(num)),
		// 	static_cast<std::int8_t>(std::round(num * 100) - std::trunc(num) * 100)
		// );
    }

    explicit operator double() const {
        return m_base + m_decimal / 100.0;
    }

    explicit operator double() {
        return m_base + m_decimal / 100.0;
    }

    bool operator==(const FixedPoint2& other) const {
        // std::cout << "1st: " << *this << ", other = " << other << "\n";
        return m_base == other.m_base && m_decimal == other.m_decimal;
    }

    FixedPoint2 operator-() {
        return FixedPoint2( -m_base, -m_decimal);
    }

    FixedPoint2 operator+(const FixedPoint2& other) const {
        return FixedPoint2(static_cast<double>(*this) + static_cast<double>(other));
    }

    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp);
    friend std::istream& operator>>(std::istream& in, FixedPoint2& fp);
    

    friend bool testDecimal(const FixedPoint2 &fp);

};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp) {
    out << static_cast<double>(fp);
    return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp) {
    double d{};
    in >> d;
    if (in)
        fp = FixedPoint2(d);
    return in;
}

// int main()
// {
// 	FixedPoint2 a{ 34, 56 };
// 	std::cout << a << '\n';
// 	std::cout << static_cast<double>(a) << '\n';
// 	assert(static_cast<double>(a) == 34.56);

// 	FixedPoint2 b{ -2, 8 };
//     std::cout << " b = " << b << std::endl;
// 	assert(static_cast<double>(b) == -2.08);

// 	FixedPoint2 c{ 2, -8 };
// 	assert(static_cast<double>(c) == -2.08);

// 	FixedPoint2 d{ -2, -8 };
// 	assert(static_cast<double>(d) == -2.08);

// 	FixedPoint2 e{ 0, -5 };
// 	assert(static_cast<double>(e) == -0.05);

// 	FixedPoint2 f{ 0, 10 };
//     std::cout << " f = " << f << std::endl;

// 	assert(static_cast<double>(f) == 0.1);

// 	return 0;
// }

// Now let’s handle the case where the fractional portion is out of bounds. We have two reasonable strategies here:

// > Step #3
// Clamp the fraction portion (if >99, set to 99).
// Treat overflow as relevant (if >99, reduce by 100 and add 1 to base).
// In this exercise, we’ll treat decimal overflow as relevant, as this will be useful in the next step.

// The following should run and print:
// 2.04
// 2.04


// You will need to make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
// bool testDecimal(const FixedPoint2 &fp)
// {
//     if (fp.m_base >= 0)
//         return fp.m_decimal >= 0 && fp.m_decimal < 100;
//     else
//         return fp.m_decimal <= 0 && fp.m_decimal > -100;
// }

// int main()
// {
// 	FixedPoint2 a{ 1, 104 };
// 	std::cout << a << '\n';
// 	std::cout << static_cast<double>(a) << '\n';
// 	assert(static_cast<double>(a) == 2.04);
// 	assert(testDecimal(a));

// 	FixedPoint2 b{ 1, -104 };
// 	assert(static_cast<double>(b) == -2.04);
// 	assert(testDecimal(b));

// 	FixedPoint2 c{ -1, 104 };
// 	assert(static_cast<double>(c) == -2.04);
// 	assert(testDecimal(c));

// 	FixedPoint2 d{ -1, -104 };
// 	assert(static_cast<double>(d) == -2.04);
// 	assert(testDecimal(d));

// 	return 0;
// }

// > Step #4
// Now add a constructor that takes a double. The follow program should run:

// int main()
// {
// 	FixedPoint2 a{ 0.01 };
// 	assert(static_cast<double>(a) == 0.01);

// 	FixedPoint2 b{ -0.01 };
// 	assert(static_cast<double>(b) == -0.01);

// 	FixedPoint2 c{ 1.9 }; // make sure we handle single digit decimal
//     std::cout << "c =  "<< static_cast<double>(c) << '\n';
// 	assert(static_cast<double>(c) == 1.9);

// 	FixedPoint2 d{ 5.01 }; // stored as 5.0099999... so we'll need to round this
// 	assert(static_cast<double>(d) == 5.01);

// 	FixedPoint2 e{ -5.01 }; // stored as -5.0099999... so we'll need to round this
// 	assert(static_cast<double>(e) == -5.01);

// 	// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
// 	FixedPoint2 f { 106.9978 }; // should be stored with base 107 and decimal 0
// 	assert(static_cast<double>(f) == 107.0);

// 	// Handle case where the argument's decimal rounds to -100 (need to decrease base by 1)
// 	FixedPoint2 g { -106.9978 }; // should be stored with base -107 and decimal 0
// 	assert(static_cast<double>(g) == -107.0);

// 	return 0;
// }

// > Step #5

// Overload operator==, operator>>, operator- (unary), and operator+ (binary).

// The following program should run:


int main()
{
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}