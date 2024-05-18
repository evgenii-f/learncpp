// Write a class template named Triad that has 3 private data members with 
// independent type template parameters. The class should have a constructor, 
// access functions, and a print() member function that is defined outside the class.

// The following program should compile and run (see the given main)


#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad {
private:
    T m_x;
    U m_y;
    V m_z;

public:
    Triad(const T& x, const U& y, const V& z);

    const T& first() const;
    const U& second() const;
    const V& third() const;

    void print() const;
};

template <typename T, typename U, typename V>
Triad<T, U, V>::Triad(const T& x, const U& y, const V& z)
    : m_x { x }, m_y { y }, m_z { z }
{
}

template <typename T, typename U, typename V>
const T& Triad<T, U, V>::first() const { return m_x; }

template <typename T, typename U, typename V>
const U& Triad<T, U, V>::second() const { return m_y; }

template <typename T, typename U, typename V>
const V& Triad<T, U, V>::third() const { return m_z; }

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const {
    std::cout << "(" << m_x << ", " << m_y << ", " << m_z << ")\n";
};

// this was given
int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}