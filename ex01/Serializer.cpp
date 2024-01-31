#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(Serializer const& copy)
{
    *this = copy;
}

Serializer& Serializer::operator=(Serializer const& copy)
{
    (void) copy;
    return (*this);
}

uintptr_t Serializer::serializer(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}