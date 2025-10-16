#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // --- Test with std::vector ---
    std::vector<int> v;
    for (int i = 1; i <= 5; ++i)
        v.push_back(i * 10); // 10, 20, 30, 40, 50

    try {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Vector error: " << e.what() << std::endl;
    }

    // --- Test with std::list ---
    std::list<int> l;
    for (int i = 1; i <= 5; ++i)
        l.push_back(i * 100); // 100, 200, 300, 400, 500

    try {
        std::list<int>::iterator it = easyfind(l, 400);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "List error: " << e.what() << std::endl;
    }

    // --- Attempt to find non-existent value ---
    try {
        std::list<int>::iterator it = easyfind(l, 999);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "List error (not found): " << e.what() << std::endl;
    }

    return 0;
}
