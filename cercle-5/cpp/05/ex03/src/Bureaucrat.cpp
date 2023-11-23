#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){
    std::cout << "Bureaucrat Default Constructor of : " << this->_name << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat & src){
    std::cout << "Bureaucrat Copy Constructor of : " << this->_name << std::endl;
    if (src._grade < 1)
        throw(GradeTooHighException());
    else if (src._grade > 150)
        throw(GradeTooLowException());
    else
        this->_grade = src._grade;
}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs){
    std::cout << "Bureaucrat Assign Constructor of : " << this->_name << std::endl;
    if (rhs._grade < 1)
        throw(GradeTooHighException());
    else if (rhs._grade > 150)
        throw(GradeTooLowException());
    else
        this->_grade = rhs._grade;
    return *this;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
    std::cout << "Bureaucrat Constructor of : " << this->_name << std::endl;
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
    else
        this->_grade = grade;
}
Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Destructor of : " << this->_name << std::endl;
}
const std::string & Bureaucrat::getName() const{
    return this->_name;
}
int Bureaucrat::getGrade() const{
    return this->_grade;
}
void Bureaucrat::incrementGrade(){
    this->_grade -= 1;
    if (this->_grade < 1)
        throw(GradeTooHighException());
}
void Bureaucrat::decrementGrade(){
    this->_grade += 1;
    if (this->_grade > 150)
        throw(GradeTooLowException());
}
std::ostream & operator<<(std::ostream &out, const Bureaucrat & rhs){
    return out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
}

void Bureaucrat::signForm(AForm & f)const{
    if (f.getIsSigned())
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	else {
		if (this->_grade <= f.getSignGrade())
			f.beSigned(*this);
		else {
			std::cout << this->getName() << " couldn't sign " << f.getName() << " because is grade is too low." << std::endl;
			throw AForm::GradeTooLowException();
		}
	}
}
void Bureaucrat::executeForm(const AForm & form){
    if (this->getGrade() > form.getExecGrade()) {
		std::cerr << this->_name << " couldn't execute the form: " << form.getName() << ", because it's grade is too low." << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (!form.getIsSigned()) {
		std::cerr << this->_name << " couldn't execute the form: " << form.getName() << ", because it isn't signed." << std::endl;
		throw AForm::NotSignedException();
	}
	else {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << "." << std::endl;
	}
}