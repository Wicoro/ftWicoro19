#ifndef C_HPP
#define C_HPP

#include <string>
#include "Base.hpp"

class C : public Base{
private:
    std::string type;

public:
    C();
    C(const C&);
    C& operator=(const C&);
    ~C();

    std::string getType() const;
};

#endif
