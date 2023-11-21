#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
    private:
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _isSigned;
    protected:
        void isExecutable(const Bureaucrat & b) const;
    public:
        AForm();
        AForm(const std::string name, const int signGrade, const int execGrade);
        AForm(const AForm &src);
        AForm & operator=(const AForm & rhs);
        virtual ~AForm();
        void beSigned(Bureaucrat b);
        const std::string getName()const;
        bool getIsSigned()const;
        void setIsSigned(bool isSigned);
        int getSignGrade()const;
        int getExecGrade()const;
        virtual void execute(const Bureaucrat & executor) const = 0;
        class GradeTooHighException : public std::exception{
            public:
                virtual const char * what() const throw(){
                    return "AForm::GradeTooHighException";
                }
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char * what() const throw(){
                    return "AForm::GradeTooLowException";
                }
        };
        class NotSignedException : public std::exception{
            public:
                virtual const char * what() const throw(){
                    return "AForm::NotSignedException";
                }
        };
};
std::ostream & operator<<(std::ostream &out, const AForm & rhs);

#endif