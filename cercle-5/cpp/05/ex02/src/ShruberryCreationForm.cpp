#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm() : AForm("ShruberryCreationForm", 145, 137), _target(""){

}
ShruberryCreationForm::ShruberryCreationForm(const std::string & target) : AForm("ShruberryCreationForm", 145, 137), _target(target){

}
ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm & src) : AForm("ShruberryCreationForm", 145, 137), _target(src.getTarget()){

}
ShruberryCreationForm & ShruberryCreationForm::operator=(const ShruberryCreationForm & rhs){
    (void)rhs;
	return *this;
}
ShruberryCreationForm::~ShruberryCreationForm(){

}
const std::string & ShruberryCreationForm::getTarget(){
    return this->_target;
}
void ShruberryCreationForm::execute(const Bureaucrat & executor)const{
    std::ofstream file;
    std::string name;

    this.
}