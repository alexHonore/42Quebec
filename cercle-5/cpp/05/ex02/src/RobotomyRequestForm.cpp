#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target(""){

}
RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("RobotomyRequestForm", 72, 45), _target(target){

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src), _target(src._target){

}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs){
    (void)rhs;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){

}
const std::string & RobotomyRequestForm::getTarget(){

}
void RobotomyRequestForm::execute(const Bureaucrat & executor)const{

}