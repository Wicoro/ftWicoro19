#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("Michael", 0);
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Jim", 151);
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Pam", 2);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
}
