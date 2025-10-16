#ifndef A_HPP
#define A_HPP

#include <string>
#include "Base.hpp"

class A : public Base {
private:
    std::string type;

public:
    A();
    ~A();

    std::string getType() const;
};

#endif
