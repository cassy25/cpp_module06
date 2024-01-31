#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
    int value;
    Data(int val) : value(val){}
};

class Serializer
{
    public:
        static uintptr_t serializer(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        Serializer();
        ~Serializer();
        Serializer(Serializer const& copy);
        Serializer& operator=(Serializer const& copy);
};

#endif