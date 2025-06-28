#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed {
private:
	int val;
	const static int fractional_bit = 8;

public:
	Fixed();
	Fixed(const int intVal);
	Fixed(const float floatVal);

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(const int raw);
	float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif