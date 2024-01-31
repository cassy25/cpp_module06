#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter const& copy)
{
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& copy)
{
    (void)copy;
    return (*this);
}

void ScalarConverter::convert(std::string const& value)
{
    std::cout << "Original literal : " << value << std::endl << std::endl;
    if (checkStr(value) == 0)
        return ;
    convertChar(value);
    convertInt(value);
    convertFloat(value);
    convertDouble(value);
}

void ScalarConverter::convertChar(std::string const& value)
{
    int newValue = std::atoi(value.c_str());
    if ((newValue >= 1 && newValue <= 31) || newValue == 127)
        std::cerr << "Char : Cannot convert" << std::endl;
    else if (value.size() == 1 && (newValue >= 32 && newValue <= 126))
    {
        char charValue = static_cast<char>(value[0]);
        std::cout << "Char : '" << charValue << "'" << std::endl;
    }
    else if (newValue >= 32 && newValue <= 126)
    {
        char asciiChar = static_cast<char>(newValue);
        std::cout << "Char : '" << asciiChar << "'" << std::endl;
    }
    else
        std::cerr << "Char : Cannot convert to char." << std::endl;
}

void ScalarConverter::convertInt(std::string const& value)
{
    if ((value[0] == '-' || value[0] == '+') && isdigit(value[1]))
    {
        int intValue = static_cast<int>(std::atoi(value.c_str()));
        std::cout << "Int : " << intValue << std::endl;
    }
    else if (isdigit(value[0]))
    {
        int intValue = static_cast<int>(std::atoi(value.c_str()));
        std::cout << "Int : " << intValue << std::endl;
    }
    else 
        std::cerr << "Int : Cannot convert in int." << std::endl;
}

void ScalarConverter::convertFloat(std::string const& value)
{
    if ((value[0] == '-' || value[0] == '+') && isdigit(value[1]))
    {
        if (value.find('.') != std::string::npos && (value.length() > 0) && value[value.length() - 1] != 'f')
            std::cout << "Float : " << value << "f" << std::endl;
        else if (value.find('.') != std::string::npos && (value.length() > 0) && value[value.length() - 1] == 'f')
            std::cout << "Float : " << value << std::endl;
        else
            std::cout << "Float : " << value << ".0f" << std::endl;
    }
    else if (isdigit(value[0]))
    {
        if (value.find('.') != std::string::npos && (value.length() > 0) && value[value.length() - 1] != 'f')
            std::cout << "Float : " << value << "f" << std::endl;
        else if (value.find('.') != std::string::npos && (value.length() > 0) && value[value.length() - 1] == 'f')
            std::cout << "Float : " << value << std::endl;
        else
            std::cout << "Float : " << value << ".0f" << std::endl;
    }
    else
    {
        std::cerr << "Float : Cannot convert in Float." << std::endl;
    }
}

void ScalarConverter::convertDouble(std::string const& value)
{
    if ((value[0] == '-' || value[0] == '+') && isdigit(value[1]))
    {
        if (value.find('.') != std::string::npos && (value.length() > 0 && value[value.length() - 1] != 'f'))
            std::cout << "Double : " << value << std::endl;
        else if (value.find('.') != std::string::npos && (value.length() > 0 && value[value.length() - 1] == 'f'))
        {
            std::string newValue = value.substr(0, value.length() - 1);
            std::cout << "Double : " << newValue << std::endl;
        }
        else
        {
            std::cout << "Double : " << value << ".0" << std::endl;
        }
    }
    else if (isdigit(value[0]))
    {
        if (value.find('.') != std::string::npos && (value.length() > 0 && value[value.length() - 1] != 'f'))
            std::cout << "Double : " << value << std::endl;
        else if (value.find('.') != std::string::npos && (value.length() > 0 && value[value.length() - 1] == 'f'))
        {
            std::string newValue = value.substr(0, value.length() - 1);
            std::cout << "Double : " << newValue << std::endl;
        }
        else
        {
            std::cout << "Double : " << value << ".0" << std::endl;
        }
    }
    else
    {
        double newValue = static_cast<double>(value[0]);
        std::cout << "Double : " << newValue << ".0" << std::endl;
    }
}

int ScalarConverter::checkStr(std::string const& value)
{
    if (value == "-inff" || value == "-inf")
    {
        std::cout << "Char : impossible" << std::endl;
        std::cout << "Int : impossible" << std::endl;
        std::cout << "Float : -inff" << std::endl;
        std::cout << "Double : -inf" << std::endl;
        return (0);
    }
    else if (value == "+inff" || value == "+inf")
    {
        std::cout << "Char : impossible" << std::endl;
        std::cout << "Int : impossible" << std::endl;
        std::cout << "Float : +inff" << std::endl;
        std::cout << "Double : +inf" << std::endl;
        return (0);
    }
    else if (value == "nan" || value == "nanf")
    {
        std::cout << "Char : impossible" << std::endl;
        std::cout << "Int : impossible" << std::endl;
        std::cout << "Float : nanf" << std::endl;
        std::cout << "Double : nan" << std::endl;
        return (0);
    }
    else if (value.length() == 1)
    {
        if (value >= "a" && value <= "z")
        {
            std::cout << "Char : " << value << std::endl;
            std::cout << "Int : impossible" << std::endl;
            std::cout << "Float : impossible" << std::endl;
            std::cout << "Double : impossible" << std::endl;
            return (0);
        }
    }
    return (1);
}