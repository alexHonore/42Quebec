#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;
class RobotomyRequestForm : public virtual AForm {
    private:
        const std::string _target;
    protected:
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);
        ~RobotomyRequestForm();
        const std::string & getTarget();
        virtual void execute(const Bureaucrat & executor)const;
};

#endif