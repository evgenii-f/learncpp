#include <iostream>

template <int N>
int factorial() {
    static_assert(N >= 0, "Factorial of negative number is not defined");
    int res = 1;
    for (int i = N - 1; i > 0; --i) {
        res *= i;
    }
    return res;
}


int main() {
    std::cout << factorial<5>() << '\n'; // 120
    std::cout << factorial<10>() << '\n'; // 3628800
    std::cout << factorial<0>() << '\n'; // 1
    std::cout << factorial<-1>() << '\n'; // compile-time error
}