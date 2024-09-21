// Write your own integer array class named IntArray from scratch (do not use std::array or std::vector). 
// Users should pass in the size of the array when it is created, and the array should be dynamically allocated. 
// Use assert statements to guard against bad data.
//  Create any constructors or overloaded operators needed to make the following program operate correctly and print:
// 5 8 2 3 6
// 5 8 2 3 6

#include <iostream>
#include <cassert>

class IntArray{
private:
    int* m_dataPtr;
    std::size_t m_capacity{0};

public:
    IntArray(std::size_t size) : m_capacity{ size } {
        assert(m_capacity >= 0 && "IntArray Size must be not negative!");
        m_dataPtr = new int[m_capacity];
    }

    //copy constructor
    IntArray(const IntArray& other) {
        delete[] m_dataPtr;
        m_capacity = other.m_capacity;
        m_dataPtr = new int[other.m_capacity];
        for (int i{0}; i < m_capacity; ++i) {
            m_dataPtr[i] = other.m_dataPtr[i];
        }    
    }

    // destructor
    ~IntArray() {
        delete[] m_dataPtr;
    }

    IntArray& operator=(const IntArray& other) {
        if (this == &other) {
            return *this;
        }
        delete[] m_dataPtr;
        m_capacity = other.m_capacity;
        m_dataPtr = new int[other.m_capacity];
        for (int i{0}; i < m_capacity; ++i) {
            m_dataPtr[i] = other.m_dataPtr[i];
        }
        return *this;    
    }

    int& operator[](std::size_t index) {
        assert(index >= 0 && index < m_capacity && "index out of bounds!");
        return m_dataPtr[index];
    }

    const int operator[](std::size_t index) const {
        assert(index >= 0 && index < m_capacity && "index out of bounds!");
        return m_dataPtr[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const IntArray& arr);



};

std::ostream& operator<<(std::ostream& out, const IntArray& arr) {
    for (int i{0}; i < arr.m_capacity; ++i) {
        out << arr[i] << ' ';
    }
    return out;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}


