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
    this->_isSigned = rhs._isSigned;
    return *this;
}
Form::~Form(){

}
void Form::setIsSigned(bool isSigned){
    this->_isSigned = isSigned; 
}
void Form::beSigned(Bureaucrat b){
    if (this->getIsSigned()){
        std::cout << "Already signed." << std::endl;
        return;
    }
    if (b.getGrade() <= this->getSignGrade()){
        this->setIsSigned(true);
        std::cout << b.getName() << " signed " << this->getName() << std::endl;
        b.signForm(*this);
    }
    else{
        b.signForm(*this);
        throw Form::GradeTooLowException();
    }
}
const std::string Form::getName()const{
    return this->_name;
}
bool Form::getIsSigned()const{
    return this->_isSigned;
}
int Form::getSignGrade()const{
    return this->_signGrade;
}
int Form::getExecGrade()const{
    return this->_execGrade;
}
std::ostream & operator<<(std::ostream &out, const Form & rhs){
    return out << rhs.getName() << ", Sign grade: " << rhs.getSignGrade() << ". Exec grade: " << rhs.getExecGrade() << "." << std::endl;
}