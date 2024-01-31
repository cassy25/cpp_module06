#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>

class ScalarConverter
{
    public:
        static void convert(std::string const& value);

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const& copy);
        ScalarConverter& operator=(ScalarConverter const& copy);
        static int checkStr(std::string const& value);
        static void convertChar(std::string const& value);
        static void convertInt(std::string const& value);
        static void convertFloat(std::string const& value);
        static void convertDouble(std::string const& value);
};

#endif