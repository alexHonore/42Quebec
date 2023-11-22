#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target(""){

}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm("ShrubberyCreationForm", 145, 137), _target(src._target){

}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs){
    (void)rhs;
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){

}
const std::string & ShrubberyCreationForm::getTarget(){
    return this->_target;
}
void ShrubberyCreationForm::execute(const Bureaucrat & executor)const{
	std::string	file = this->getName() + "_shrubbery.txt";
    std::ofstream fs(file, std::ios::app);
    // std::ofstream fs(file.c_str(), std::ios::out | std::ios::trunc);
	// fs.exceptions(fs.failbit);
    isExecutable(executor);
    if (fs && fs.isOpen()){
        fs << "                      v .   ._, |_  .," << std::endl;
        fs << "           `-._\\/  .  \\ /    |/_" << std::endl;
        fs << "               \\  _\\, y | \\//" << std::endl;
        fs << "         _\\_.___\\, \\/ -.\\||" << std::endl;
        fs << "           `7-,--.`._||  / / ," << std::endl;
        fs << "           /'     `-. `./ / |/_.'" << std::endl;
        fs << "                     |    |//" << std::endl;
        fs << "                     |_    /" << std::endl;
        fs << "                     |-   |" << std::endl;
        fs << "                     |   =|" << std::endl;
        fs << "                     |    |" << std::endl;
        fs << "--------------------/ ,  . \\--------._" << std::endl;
	    fs.close();
    }
    else{
        std::cerr << "Cannot access the file." << std::endl;
        throw std::invalid_argument("- Error in ShrubberyCreationForm::execute()");
    }
    return;
}