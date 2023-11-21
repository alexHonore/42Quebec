#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
    protected:
    public:
        Form();
        Form(const std::string name, const int signGrade, const int execGrade);
        Form(const Form &src);
        Form & operator=(const Form & rhs);
        ~Form();
        void beSigned(Bureaucrat b);
        const std::string getName()const;
        bool getIsSigned()const;
        void setIsSigned(bool isSigned);
        int getSignGrade()const;
        int getExecGrade()const;
        class GradeTooHighException : public std::exception{
            public:
                virtual const char * what() const throw(){
                    return "Form::GradeTooHighException";
                }
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char * what() const throw(){
                    return "Form::GradeTooLowException";
                }
        };
};
std::ostream & operator<<(std::ostream &out, const Form & rhs);

#endif