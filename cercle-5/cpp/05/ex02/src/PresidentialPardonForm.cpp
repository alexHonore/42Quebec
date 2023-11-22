#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target(""){

}
PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("PresidentialPardonForm", 25, 5), _target(target){

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src), _target(src._target){

}
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs){
    (void)rhs;
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){

}
const std::string & PresidentialPardonForm::getTarget(){

}
void PresidentialPardonForm::execute(const Bureaucrat & executor)const{

}