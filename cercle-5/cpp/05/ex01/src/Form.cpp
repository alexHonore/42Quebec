#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false){
}
Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false){

    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    
}
Form::Form(const Form &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned){

}
Form & Form::operator=(const Form & rhs){
    this->_execGrade = rhs._execGrade;
    this->_signGrade = rhs._signGrade;
    this->_isSigned = rhs._isSigned;
    return *this;
}
Form::~Form(){

}
void Form::beSigned(Bureaucrat b){

}
const std::string Form::getName(){

}
bool Form::getIsSigned(){

}
const int Form::getSignGrade(){

}
const int Form::getExecGrade(){

}
std::ostream & operator<<(std::ostream &out, const Form & rhs){

}