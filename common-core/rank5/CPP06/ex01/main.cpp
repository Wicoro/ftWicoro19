#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.val = 42;

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Serialized: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Data value via deserialized pointer: " << ptr->val << std::endl;

    if (ptr == &data)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Error: pointers don't match!" << std::endl;

    return 0;
}
