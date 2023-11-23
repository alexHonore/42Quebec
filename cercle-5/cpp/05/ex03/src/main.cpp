#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << std::endl << "\033[1;33mTEST 1\033[1;0m" << std::endl;
	
	AForm * form = 0;
	Bureaucrat vet = Bureaucrat();
	Intern rookie = Intern();

	try {
		form = rookie.makeForm("shrubbery creation", "Jardin");
		std::cout << vet << std::endl;
		std::cout << form << std::endl;
		vet.executeForm(*form);
		vet.signForm(*form);
		std::cout << form << std::endl;
		vet.executeForm(*form);
		delete form;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;33mTEST 2\033[1;0m" << std::endl;
	
	AForm * form2 = 0;
	Bureaucrat vet2 = Bureaucrat("vet", 1);
	Intern rookie2 = Intern();

	try {
		form2 = rookie2.makeForm("shrubbery creation", "Jardin");
		std::cout << vet2 << std::endl;
		std::cout << form2 << std::endl;
		vet2.executeForm(*form2);
		vet2.signForm(*form2);
		std::cout << form2 << std::endl;
		vet2.executeForm(*form2);
		delete form2;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[1;33mTEST 3\033[1;0m" << std::endl;
	
	AForm * form3 = 0;
	Bureaucrat vet3 = Bureaucrat("vet", 1);
	Intern rookie3 = Intern();

	try {
		form3 = rookie3.makeForm("shrubbery creation", "Jardin");
		std::cout << vet3 << std::endl;
		std::cout << form3 << std::endl;
		vet3.signForm(*form3);
		vet3.executeForm(*form3);
		std::cout << form3 << std::endl;
		delete form3;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}