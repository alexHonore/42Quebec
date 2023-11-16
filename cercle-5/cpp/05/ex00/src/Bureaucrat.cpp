#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){

}
Bureaucrat::Bureaucrat(const Bureaucrat & src){
    *this = src;
}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs){
    this->_name = rhs._name;
    this->_grade = rhs._grade;
    return *this;
}
Bureaucrat::Bureaucrat(std::string name, int grade){
    this->_name = name;
    this->_grade = grade;
}
Bureaucrat::~Bureaucrat(){

}
const std::string Bureaucrat::getName(){
    return this->_name;
}
int Bureaucrat::getGrade(){
    return this->_grade;
}
void Bureaucrat::incrementGrade(){
    this->_grade -= 1;
    if (this->_grade < 1)
        throw exception;
}
void Bureaucrat::decrementGrade(){
    this->_grade += 1;
    if (this->_grade > 150)
        throw exception;
}
class GradeTooHighException : public std::exception{
    public:
        virtual const char *what() const throw();
};
class GradeTooLowException : public std::exception{
    public:
        virtual const char *what() const throw();
};
std::ostream & Bureaucrat::operator<<(std::ostream out, const Bureaucrat & rhs){
    std::cout << this->_name << ", bureaucrat grade " this->_grade << "." << std::endl;
}
