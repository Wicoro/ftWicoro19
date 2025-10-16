#include "C.hpp"

C::C() : type("C") {}
C::~C() {}

std::string C::getType() const {
    return type;
}

