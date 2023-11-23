#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <stdlib.h>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;
class RobotomyRequestForm : public virtual AForm {
    private:
        std::string _target;
    protected:
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);
        ~RobotomyRequestForm();
        const std::string & getTarget();
        virtual void execute(const Bureaucrat & executor)const;
        class OperationNotPassException : public std::exception{
            public:
                virtual const char * what() const throw(){
                    return "AForm::OperationNotPassException -> The robotomy did not work...";
                }
        };
};

#endif