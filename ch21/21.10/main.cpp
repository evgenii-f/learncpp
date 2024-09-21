// Write a class named MyString that holds a std::string. Overload operator<< to output 
// the string. Overload operator() to return the substring that starts at the index 
// of the first parameter (as a MyString). The length of the substring should be defined by the second parameter.

// The following code should run and print
// world
#include <iostream>
#include <string>
#include <string_view>–

class MyString {
private:
    std::string m_s{};

public:
    MyString(const std::string_view s = {} ) : m_s{ s } {
    }

    // std::ostream& operator<<(std::ostream& out) {
    //     out << m_s;
    //     return out;
    // }

    // MyString operator()(int start = 0, int length = -1) {
    //     if (length >= 0 ) {
    //         return MyString(m_s.substr(start, length));
    //     }
    //     return MyString(m_s.substr(start));
        // // Since std::string::substr returns a std::string, and a std::string won't implicitly convert to a std::string_view (which our constructor needs)
		// // We must be explicit about the fact that we want such a conversion to take place
		// return MyString { m_s.substr(
		// 	static_cast<std::string::size_type>(start),
		// 	static_cast<std::string::size_type>(length)
		// 	)};
    // }

    // Update operator() from the prior quiz solution to return the substring as a std::string_view instead.

    // Hint: std::string::substr() returns a std::string. std::string_view::substr() returns a std::string_view. 
    // Be very careful not to return a dangling std::string_view!.

    std::string_view operator()(int start=0, int length=-1) {
        if (length == -1) {
            return std::string_view(m_s).substr(
                static_cast<std::string_view::size_type>(start)
            );
        }
        return std::string_view(m_s).substr(
            static_cast<std::string_view::size_type>(start),
			static_cast<std::string_view::size_type>(length)
        );
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& s)
	{
		out << s.m_s;

		return out;
	}
};

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}