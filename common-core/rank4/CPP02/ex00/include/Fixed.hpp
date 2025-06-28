#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed {
private:
	int val;
	const static int fractional_bit = 8;

public:
	Fixed();

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(const int raw);
};

#endif