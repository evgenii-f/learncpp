// A factorial of an integer N (written N!) is defined as the product (multiplication) of all the numbers between 1 and
//  N (0! = 1). Write a recursive function called factorial that returns the factorial of the input. 
//  Test it with the first 7 factorials.

#include <iostream>
#include <array>
#include <algorithm>

int nCalls{ 0 };
int factorial(int N, int memo[]) {
    // std::cout << "\t fact(" << N << ") was called, memoVal = " << memo[N] << std::endl;
    nCalls++;
    // if (memo[N-1] > 0) return memo[N-1];
    if (N == 0 || N == 1 || N == 2) return N;

    memo[N] = N * factorial(N-1, memo);
    return memo[N];   
}

int factorial(int N) {
    nCalls++;
    if (N == 0 || N == 1 || N == 2) return N;

    return N * factorial(N-1);
}



int main() {
    const std::size_t N{ 200 };
    int memo[N+1] {};
    std::fill(memo, memo+N+1, -1);
    // factorial(N, memo);
    std::cout << "Factorial of " << 5 << " = " << factorial(N, memo);
    std::cout << ", there was " << nCalls << " function calls." << std::endl;

    return 0;
}