//Write definitions for the following. Use CTAD where possible
#include "vector"
#include "string_view"

int main() {
    using namespace std::literals::string_view_literals;
    // a) A std::vector initialized with the first 6 even numbers.
    std::vector vecA{ 2, 4, 6, 8, 10, 12 };
    // b) A constant std::vector initialized with the values 1.2, 3.4, 5.6, and 7.8.
    const std::vector vecB{ 1.2, 3.4, 5.6, 7.8 };
    // c) A constant std::vector of std::string_view initialized with the names “Alex”, “Brad”, “Charles”, and “Dave”.
    const std::vector vecC{ "Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv};
    // d) A std::vector with the single element value 12.
    std::vector vecD{ 12 };
    // e) A std::vector with 12 int elements, initialized to the default values.
    std::vector<int> vecE( 12 );
    return 0;
} 