#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;
class ShruberryCreationForm : public AForm {
    private:
        const std::string _target;
    protected:
    public:
        ShruberryCreationForm();
        ShruberryCreationForm(const std::string & target);
        ShruberryCreationForm(const ShruberryCreationForm & src);
        ShruberryCreationForm & operator=(const ShruberryCreationForm & rhs);
        ~ShruberryCreationForm();
        const std::string & getTarget();
        virtual void execute(const Bureaucrat & executor)const;
};

#endif