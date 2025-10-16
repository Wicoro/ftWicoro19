#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base* Base::generate() {
    int r = std::rand() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void Base::identify(Base* p) {
    if (p == NULL) {
        std::cout << "Null pointer received" << std::endl;
        return;
    }
    std::cout << "Pointer points to type: " << p->getType() << std::endl;
}

void Base::identify(Base& p) {
    std::cout << "Reference to type: " << p.getType() << std::endl;
}