#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false){
}
AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false){

    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    
}
AForm::AForm(const AForm &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned){

}
AForm & AForm::operator=(const AForm & rhs){
    this->_isSigned = rhs._isSigned;
    return *this;
}
AForm::~AForm(){

}
void AForm::setIsSigned(bool isSigned){
    this->_isSigned = isSigned; 
}
void AForm::beSigned(Bureaucrat b){
    if (this->getIsSigned()){
        std::cout << "Already signed." << std::endl;
        return;
    }
    if (b.getGrade() <= this->getSignGrade()){
        this->setIsSigned(true);
        b.signForm(*this);
    }
    else{
        b.signForm(*this);
        throw AForm::GradeTooLowException();
    }
}
const std::string AForm::getName()const{
    return this->_name;
}
bool AForm::getIsSigned()const{
    return this->_isSigned;
}
int AForm::getSignGrade()const{
    return this->_signGrade;
}
int AForm::getExecGrade()const{
    return this->_execGrade;
}
std::ostream & operator<<(std::ostream &out, const AForm & rhs){
    return out << rhs.getName() << ", Sign grade: " << rhs.getSignGrade() << ". Exec grade: " << rhs.getExecGrade() << "." << std::endl;
}
void AForm::isExecutable(const Bureaucrat & b) const{
    if (b.getGrade() > this->getExecGrade())
        throw (GradeTooLowException("Bureaucrat cannot execute the form."));
    if (this->getIsSigned() == false)
        throw (NotSignedException("The form isn't signed."));
}