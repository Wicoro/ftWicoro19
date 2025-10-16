#include "A.hpp"

A::A() : type("A") {}
A::~A() {}

std::string A::getType() const {
    return type;
}

