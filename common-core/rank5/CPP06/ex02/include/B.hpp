#ifndef B_HPP
#define B_HPP

#include <string>
#include "Base.hpp"

class B : public Base {
private:
    std::string type;

public:
    B();
    ~B();

    std::string getType() const;
};

#endif
