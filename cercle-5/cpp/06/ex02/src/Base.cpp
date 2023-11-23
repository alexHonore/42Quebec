#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate() {
	Base *result;
	int num = std::rand() % 3;

    if (num == 0){
		result = new A();
		std::cout << "generated an instace of A\n";
	}
    else if (num == 1){
		result = new B();
		std::cout << "generated an instace of B\n";
	}
    else if (num == 2){
		result = new C();
		std::cout << "generated an instace of C\n";
	}
    else
        result = NULL;
	return result;
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "Found A *" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Found B *" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Found C *" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Found A &" << std::endl;
		return;
	}
	catch (const std::exception& e) {
    }

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Found B &" << std::endl;
		return;
	}
	catch (const std::exception& e) {
    }

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Found C &" << std::endl;
		return;
	}
	catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
	}
}