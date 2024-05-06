// Create a class template named Triad that has 3 members of the same template type. 
// Also create a function template named print that can print a Triad. 
// The following program should compile (see main)

#include <iostream>

template <typename T>
struct Triad {
    T x;
    T y;
    T z;
};

// CTAD
template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>&s triad) {
    std::cout << "[" << triad.x << ", " << triad.y << ", " << triad.z << "]";
}

// the output should be [1, 2, 3][1.2, 3.4, 5.6]
int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}