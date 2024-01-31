#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate()
{
    int randomValue = rand() % 75;

    if (randomValue > 50)
            return (new A);
    else if (randomValue <= 25)
            return (new B);
    return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else if (p == NULL)
        std::cerr << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    if (A* derivedA = dynamic_cast<A*>(&p))
    {
        std::cout << "A" << std::endl;
    }
    else if (B* derivedB = dynamic_cast<B*>(&p))
    {
        std::cout << "B" << std::endl;
    }
    else if (C* derivedC = dynamic_cast<C*>(&p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cerr << "Unknown type" << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    int i = 0;
    while (i < 5)
    {
        Base* obj = generate();

        identify(obj);
        identify(*obj);
        delete obj;
        i++;
    }
    return 0;
}
