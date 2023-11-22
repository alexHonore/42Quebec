#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target(""){

}
RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("RobotomyRequestForm", 72, 45), _target(target){

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src), _target(src._target){

}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs){
    if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){

}
const std::string & RobotomyRequestForm::getTarget(){
    return this->_target;
}
void RobotomyRequestForm::execute(const Bureaucrat & executor)const{
    int random = rand() % 2 + 1;
    this->isExecutable(executor);
    if (random % 2){
        std::cout << "* DRILL NOICE *" << std::endl;
        system("PATH");
    }
    else{
        throw (OperationNotPassException());
    }
}