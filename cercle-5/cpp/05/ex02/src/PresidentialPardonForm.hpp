#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;
class PresidentialPardonForm : public AForm {
    private:
        const std::string _target;
    protected:
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string & target);
        PresidentialPardonForm(const PresidentialPardonForm & src);
        PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
        ~PresidentialPardonForm();
        const std::string & getTarget();
        virtual void execute(const Bureaucrat & executor)const;
};

#endif