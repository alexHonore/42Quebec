#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *base = generate();
    Base *nothing = NULL;
    identify(base);
    identify(*base);
    identify(nothing);
    delete base;
	return 0;
};