#include <iostream>
#include <string>
// 1. It’s sometimes useful to define data that travels in pairs. 
// Write a templated class named Pair1 that allows the user to define one template type 
// that is used for both values in the pair. The following function should work and print:

// Pair: 5 8
// Pair: 2.3 4.5

template <typename T>
class Pair1 {
private:
    T m_first{};
    T m_second{};
public:
    Pair1(const T& first, const T& second) : m_first{ first }, m_second{ second } 
    {
    }

    const T& first() const {
        return m_first;
    }

    const T& second() const {
        return m_second;
    }

    T& first() {
        return m_first;
    }

    T& second() {
        return m_second;
    }

};


// int main()
// {
// 	Pair1<int> p1 { 5, 8 };
// 	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

// 	const Pair1<double> p2 { 2.3, 4.5 };
// 	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

// 	return 0;
// }

// 2. Write a Pair class that allows you to specify separate types 
// for each of the two values in the pair.

// The following program should work and print:
// Pair: 5 6.7
// Pair: 2.3 4

template <typename T1, typename T2>
class Pair {
private:
    T1 m_first{};
    T2 m_second{};
public:
    Pair(const T1& first, const T2& second) : m_first{ first }, m_second{ second } 
    {
    }

    const T1& first() const {
        return m_first;
    }

    const T2& second() const {
        return m_second;
    }

    T1& first() {
        return m_first;
    }

    T2& second() {
        return m_second;
    }

};

// int main()
// {
// 	Pair<int, double> p1 { 5, 6.7 };
// 	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

// 	const Pair<double, int> p2 { 2.3, 4 };
// 	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

// 	return 0;
// }

// 3. A string-value pair is a special type of pair where the first value is always a string type, 
// and the second value can be any type. 

// Write a template class named StringValuePair that inherits from a partially specialized Pair class 
// (using std::string as the first type, and allowing the user to specify the second type).

// The following program should run and print:
// Pair: Hello 5

template <typename T>
class StringValuePair : public Pair<std::string, T> {
public:
    StringValuePair(const std::string& first, const T& second) : Pair<std::string, T>(first, second) 
    {
    }
};


// template <typename S>
// class StringValuePair : public Pair<std::string, S>
// {
// public:
// 	StringValuePair(std::string_view key, const S& value)
//                 // a std::string_view won't implicitly convert to a std::string, we must be explicit
// 		: Pair<std::string, S>{ static_cast<std::string>(key), value }
// 	{
// 	}
// };

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}