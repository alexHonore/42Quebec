#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target(""){

}
PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("PresidentialPardonForm", 25, 5), _target(target){

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src), _target(src._target){

}
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs){
    if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){

}
const std::string & PresidentialPardonForm::getTarget(){
    return this->_target;
}
void PresidentialPardonForm::execute(const Bureaucrat & executor)const{
    this->isExecutable(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}