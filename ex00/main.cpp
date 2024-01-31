#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
    }
    else
        std::cerr << "Enter only one parameter" << std::endl;
    return 0;
}
