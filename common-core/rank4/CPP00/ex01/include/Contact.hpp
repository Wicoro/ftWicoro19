#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone_nb;
    std::string secret;

    Contact() : firstname(""), lastname(""), nickname(""), phone_nb(""), secret("") {}

    ~Contact() {}
};

#endif