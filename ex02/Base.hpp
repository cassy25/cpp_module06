#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>

class Base
{
    public:
        virtual ~Base();
        Base();
};

Base*   generate();
void    identify(Base* p);
void    identify(Base &p);

#endif