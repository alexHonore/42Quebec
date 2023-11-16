#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    protected:
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat & src);
        Bureaucrat & operator=(const Bureaucrat & rhs);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        const std::string getName();
        int getGrade();
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
};
std::ostream & operator<<(std::ostream out, const Bureaucrat & rhs);


#endif