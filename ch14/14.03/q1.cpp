#include <iostream>

// q1: Provide the definition for IntPair and the print() member function here
// q2: Provide the definition for IntPair and the member functions here

// option A
struct IntPair {
    int m_x1 {};
    int m_x2 {};

    void print(const std::string_view prefix=std::string_view("")) {
        std::cout << prefix << m_x1 << ", " << m_x2 << std::endl;
    }

    bool isEqual(const IntPair& p) {
        return (p.m_x1 == m_x1) && (p.m_x2 == m_x2);
    }
};

// // option B
// struct IntPair {
//     int m_x1 {};
//     int m_x2 {};

//     void print() {
//         std::cout << m_x1 << ", " << m_x2 << std::endl;
//     }
    
//     void print(std::string_view const prefix) {
//         std::cout << prefix << m_x1 << ", " << m_x2 << std::endl;
//     }
// };


int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}