// In the following code, modify str so that its value is “I saw a blue car yesterday.”
// without repeating the string.

#include <iostream>
#include <string>

int main()
{
    std::string str{ "I saw a red car yesterday." };

    // your code
    std::string_view s { "red" };
    auto pos = str.find(s);
    auto n = s.size();
    std::string_view sNew { "blue" };
    str.replace(pos, n, sNew);

    std::cout << str << '\n'; // I saw a blue car yesterday.

    return 0;
}