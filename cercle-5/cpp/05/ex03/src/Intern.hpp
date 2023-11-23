#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern {
    private:
    protected:
    public:
        Intern();
        Intern(const Intern & src);
        Intern & operator=(const Intern & rhs);
        ~Intern();
        AForm * makeForm(std::string formName, std::string targetForm);
        
        AForm * makePresi(std::string target);
        AForm * makeRobot(std::string target);
        AForm * makeShrub(std::string target);
        class FormNotFoundException : public std::exception{
            public:
                virtual const char *what() const throw(){
                    return "Intern::FormNotFoundException";
                }
        };
};

#endif