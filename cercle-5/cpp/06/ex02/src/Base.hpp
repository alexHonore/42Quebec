#ifndef BASE_HPP
# define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {
    private:
    protected:
	public:
		virtual ~Base();
};

Base *generate();
void identify(Base *p);
void identify(Base& p);

#endif