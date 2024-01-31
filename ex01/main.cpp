#include "Serializer.hpp"

int main()
{
    Data myData(42);

    uintptr_t serializedValue = Serializer::serializer(&myData);

    Data* deserializedData = Serializer::deserialize(serializedValue);

    if (deserializedData == &myData)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cerr << "Error: Serialization and deserialization failed!" << std::endl;
}
