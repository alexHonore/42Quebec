#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string.h>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;
class ShrubberyCreationForm : public virtual AForm {
    private:
        const std::string _target;
    protected:
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);
        ~ShrubberyCreationForm();
        const std::string & getTarget();
        virtual void execute(const Bureaucrat & executor)const;
};

#endif