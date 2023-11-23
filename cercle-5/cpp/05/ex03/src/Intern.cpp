#include "Intern.hpp"

Intern::Intern(){

}
Intern::Intern(const Intern & src){
    *this = src;
}
Intern::~Intern(){

}
Intern & Intern::operator=(const Intern & rhs){
    (void) rhs;
	return *this;
}

AForm * Intern::makePresi(std::string target){return (new PresidentialPardonForm(target));}
AForm * Intern::makeRobot(std::string target){return (new RobotomyRequestForm(target));}
AForm * Intern::makeShrub(std::string target){return (new ShrubberyCreationForm(target));}

AForm * Intern::makeForm(std::string formName, std::string targetForm){
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm * (Intern::*f[3])(std::string) = {&Intern::makePresi, &Intern::makeRobot, &Intern::makeShrub};

    for(int i = 0; i < 3; i++){
        if (forms[i] == formName){
            return ((this->*f[i])(targetForm));
        }
    }
    std::cerr << "Form not found." << std::endl;
    throw (FormNotFoundException());
    return (NULL);
}