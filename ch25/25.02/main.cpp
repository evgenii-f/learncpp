#include <iostream>

class Base {
public:
    // std::string_view sayName() const {
    virtual std::string_view sayName() const {
        return "Base";
    }
};

class Derived: public Base {
public:
    // std::string_view sayName() const {
    virtual std::string_view sayName() const {
        return "Derived";
    }
};

int main() {
    Derived d {};
    Base& dRef {d};
    Base* dPtr {&d};

    std::cout << d.sayName() << "\n";
    std::cout << dRef.sayName() << "\n";
    std::cout << dPtr->sayName() << "\n";
}




