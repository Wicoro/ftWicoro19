#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Base* obj = Base::generate(); 

    Base::identify(obj);
    Base::identify(*obj); 

    delete obj;

    return 0;
}
