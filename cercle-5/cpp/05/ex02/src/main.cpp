#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
   {
   std::cout << std::endl << "\033[1;33mTESTS\033[1;0m" << std::endl;
	std::cout << "Required grades: sign 145, exec 137" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat bur11("bur11", 1);
	Bureaucrat bur12("bur12", 140);
	Bureaucrat bur13("bur13", 150);

	ShrubberyCreationForm a("form");
	ShrubberyCreationForm a2("test2");

   std::cout << std::endl << "\033[1;33mTEST1\033[1;0m" << std::endl;
	try {
		std::cout << a << std::endl;
		a.execute(bur11);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST2\033[1;0m" << std::endl;
	try {
		std::cout << bur13 << std::endl;
		std::cout << a << std::endl;
		a.beSigned(bur13);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST3\033[1;0m" << std::endl;
	try {
		std::cout << bur12 << std::endl;
		std::cout << a << std::endl;
		a.beSigned(bur12);
		bur12.executeForm(a);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST4\033[1;0m" << std::endl;
	try {
		std::cout << bur11 << std::endl;
		a.execute(bur11);
		a2.beSigned(bur11);
		bur11.executeForm(a2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "------- RobotomyRequestForm -------" << std::endl;
	std::cout << "Required grades: sign 72, exec 45" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat bur21("bur21", 1);
	Bureaucrat bur22("bur22", 70);
	Bureaucrat bur23("bur23", 100);

	RobotomyRequestForm b("Oscar");
	RobotomyRequestForm b2("Robert");

   std::cout << std::endl << "\033[1;33mTEST5\033[1;0m" << std::endl;
	try {
		std::cout << b << std::endl;
		b.execute(bur21);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST6\033[1;0m" << std::endl;
	try {
		std::cout << bur23 << std::endl;
		std::cout << b << std::endl;
		b.beSigned(bur23);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST7\033[1;0m" << std::endl;
	try {
		std::cout << bur22 << std::endl;
		std::cout << b << std::endl;
		b.beSigned(bur22);
		bur22.executeForm(b);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST8\033[1;0m" << std::endl;
	try {
		std::cout << bur21 << std::endl;
		b.execute(bur21);
		b2.beSigned(bur21);
		bur21.executeForm(b2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "------- PresidentialPardonForm -------" << std::endl;
	std::cout << "Required grades: sign 25, exec 5" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat bur31("bur31", 1);
	Bureaucrat bur32("bur32", 20);
	Bureaucrat bur33("bur33", 30);

	PresidentialPardonForm c("Luffy");
	PresidentialPardonForm c2("Peter");

   std::cout << std::endl << "\033[1;33mTEST9\033[1;0m" << std::endl;
	try {
		std::cout << c << std::endl;
		c.execute(bur31);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST10\033[1;0m" << std::endl;
	try {
		std::cout << bur33 << std::endl;
		std::cout << c << std::endl;
		c.beSigned(bur33);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST11\033[1;0m" << std::endl;
	try {
		std::cout << bur32 << std::endl;
		std::cout << c << std::endl;
		c.beSigned(bur32);
		bur32.executeForm(c);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

   std::cout << std::endl << "\033[1;33mTEST12\033[1;0m" << std::endl;
	try {
		std::cout << bur31 << std::endl;
		c.execute(bur31);
		c2.beSigned(bur31);
		bur31.executeForm(c2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
   }
}