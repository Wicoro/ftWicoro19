#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

class Contact {
private:
	std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone_nb;
    std::string secret;
public:
	// Constructor | Destructor
    Contact() : firstname(""), lastname(""), nickname(""), phone_nb(""), secret("") {}
    ~Contact() {}

	// Setters
    void setFirstName(const std::string& fname);
    void setLastName(const std::string& lname);
    void setNickname(const std::string& nname);
    void setPhoneNumber(const std::string& phone);
    void setSecret(const std::string& s);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getSecret() const;
};

#endif