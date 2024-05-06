#include <iostream>

int main() {
    int x { 10 };
    int* ptr {&x};

    std::cout << x << "\n";
    std::cout << sizeof(x) << "\n";
    std::cout << ptr << "\n";
    std::cout << sizeof(ptr) << "\n";
    std::cout << &ptr << "\n";
    std::cout << typeid(ptr).name() << "\n";

    {
        int y { 12 };
        ptr = &y;
    }
    std::cout << x << "\n";
    std::cout << *ptr << " " << &ptr << "\n";

    // check if nullptr deference crashes the programm
    short* ptr0 
    { nullptr };
    // std::cout << *ptr0 << "\n";


    return 0;
}
