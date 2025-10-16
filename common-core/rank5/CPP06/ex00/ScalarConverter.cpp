#include "include/ScalarConverter.hpp"
#include <iostream>
#include <iomanip>  // for std::fixed and std::setprecision

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void) other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {(void) other; return *this;}
ScalarConverter::~ScalarConverter() {}

static bool isInt(std::string str) {
	int	i = 0;

	if (str[0] != '-' && !isdigit(str[0]))
		return (0);
	if (str[0] == '-' && !str[1])
		return (0);
	else
		i++;
	for (size_t j = i; j < str.length(); j++) {
		if (!isdigit(str[j]))
			return (0);
	}
	return (1);
}

static bool isFloat(std::string str) {
	int i = 0;

	if (str[0] != '-' && !isdigit(str[0]))
		return (0);
	if (str[0] == '-' && !str[1])
		return (0);
	else
		i++;
	while (str[i] && str[i] != '.') {
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	i++;
	while (str[i] && str[i] != 'f') {
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	return (1);
}

static bool isDouble(std::string str) {
	int i = 0;

	if (str[0] != '-' && !isdigit(str[0]))
		return (0);
	if (str[0] == '-' && !str[1])
		return (0);
	else
		i++;
	while (str[i] && str[i] != '.') {
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	i++;
	while (str[i]) {
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	getInputType(std::string str) {
	if (str.length() == 1 && !isdigit(str[0])) {
		return 0;
	} else if (isInt(str)) {
		return 1;
	} else if (isFloat(str)) {
		return 2;
	} else if (isDouble(str)) {
		return 3;
	} else if (str == "-inf" || str == "-infF" || str == "+inf" || str == "+infV" || str == "nan" || str == "nanf" ) {
		return 4;
	} else
		return 5;
}

static int	ft_atoi(std::string str) {
	int	nb = 0;
	int	sign = 1;
	int	i = 0;

	if (str[0] == '-') {
		sign = -1;
		i++;
	}
	while (str[i]) {
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sign);
}

static float	ft_atof(std::string str) {
	float	nb = 0;
	int		sign = 1;
	int		i = 0;
	int		divisor = 0;

	if (str[0] == '-') {
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.') {
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	i++;
	while (str[i] != 'f') {
		nb *= 10;
		nb += str[i] - 48;
		i++;
		divisor++;
	}
	while (divisor > 0) {
		nb *= 0.1;
		divisor--;
	}
	return (nb * sign);
}

static float	ft_atod(std::string str) {
	float	nb = 0;
	int		sign = 1;
	int		i = 0;
	int		divisor = 0;

	if (str[0] == '-') {
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.') {
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	i++;
	while (str[i]) {
		nb *= 10;
		nb += str[i] - 48;
		i++;
		divisor++;
	}
	while (divisor > 0) {
		nb *= 0.1;
		divisor--;
	}
	return (nb * sign);
}

void ScalarConverter::convert(const std::string str) {
	int		input_type;
	char	c;
	int		i;
	float	f;
	double	d;

	input_type = getInputType(str);
	if (input_type == 5) {
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	switch (input_type)
	{
		case 0:
			c = str[0];
			i = str[0];
			f = i;
			d = i;
			break;
		case 1:
			i = ft_atoi(str);
			c = i;
			f = i;
			d = i;
			break;
		case 2:
			f = ft_atof(str);
			c = f;
			i = f;
			d = f;
			break;
		case 3:
			d = ft_atod(str);
			c = d;
			i = d;
			f = d;
			break;
		case 4:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (str == "+inf" || str == "+inff") {
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;	
			}
			if (str == "-inf" || str == "-inff") {
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;	
			}
			if (str == "nan" || str == "nanf") {
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;	
			}
			return;
	}
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f <<  "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}