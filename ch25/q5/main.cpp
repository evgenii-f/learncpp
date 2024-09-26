#include <iostream>

void sort2(int& x, int&y) {
    if (x > y) {
        auto temp = x;
        x = y;
        y = temp;
    }
}

int main()
{
    int x { 7 };
    int y { 5 };

    int* pStack {&x};
    int* pHeap {new int(19)};
    std::cout << "pStack address:" << pStack << std::endl;
    std::cout << "pHeap address:" << pHeap << std::endl;

    std::cout << x << ' ' << y << '\n'; // should print 7 5

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}