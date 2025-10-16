#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

typedef struct t_Data {
	unsigned int val;
}	Data;

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
