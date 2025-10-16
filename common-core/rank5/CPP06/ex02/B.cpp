#include "B.hpp"

B::B() : type("B") {}
B::~B() {}

std::string B::getType() const {
    return type;
}

