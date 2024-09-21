// Write a class named Average that will keep track of the average of all integers passed to it. 
// Use two members: The first one should be type std::int32_t, and used to keep track of 
// the sum of all the numbers you’ve seen so far. The second should keep track of how 
// many numbers you’ve seen so far. You can divide them to find your average.

// a) Write all of the functions necessary for the following program to run and produce the result:
// 0
// 4
// 6
// 12
// 6.5
// 7
// 7

#include <cstdint>
#include <iostream>

class Average {
private:
    std::int32_t m_sum{ 0 };
    int m_n{ 0 };

public: 
    Average& operator+=(int number);
    friend std::ostream& operator<<(std::ostream& out, const Average& avg);
};

Average& Average::operator+=(std::int32_t number) {
    m_sum += number;
    m_n++;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Average& avg) {
    double val{ avg.m_n == 0 ? 0 : static_cast<double>(avg.m_sum) / avg.m_n};
    out << val;
    return out;
};

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}