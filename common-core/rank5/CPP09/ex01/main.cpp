#include "include/RPN.hpp"
#include <sstream>

int main(int ac, char** av) {
    RPN rpn;

	if (ac != 2) {
		std::cerr << "Invalid arg count, only use 1 arg between quotes" << std::endl;
		return (1);
	}

	std::istringstream iss(av[1]);
    std::string token;
	try {
        while (iss >> token) {
            if (token.size() != 1 || std::string("0123456789+-*/").find(token[0]) == std::string::npos) {
				std::cerr << "Error: Invalid token at " << token[0] << std::endl;
				return  1;
            } else if (std::string("0123456789").find(token[0]) != std::string::npos) {
                rpn.addNb(token[0] - '0');
            } else {
				rpn.doOperation(token[0]);
			}
        }

        std::cout << "Result: " << rpn.getLVal() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

	return 0;
}

