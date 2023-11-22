#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target(""){

}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm("ShrubberyCreationForm", 145, 137), _target(src._target){

}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs){
    if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){

}
const std::string & ShrubberyCreationForm::getTarget(){
    return this->_target;
}
// std::string::c_str() transform a string to a char * (c compatible)
void ShrubberyCreationForm::execute(const Bureaucrat & executor)const{
    std::ofstream outfile;
	
    this->isExecutable(executor);
    outfile.open((this->getName() + "_shrubbery.txt").c_str());
    if (outfile && outfile.is_open()){
        outfile << "                      v .   ._, |_  .," << std::endl;
        outfile << "           `-._\\/  .  \\ /    |/_" << std::endl;
        outfile << "               \\  _\\, y | \\//" << std::endl;
        outfile << "         _\\_.___\\, \\/ -.\\||" << std::endl;
        outfile << "           `7-,--.`._||  / / ," << std::endl;
        outfile << "           /'     `-. `./ / |/_.'" << std::endl;
        outfile << "                     |    |//" << std::endl;
        outfile << "                     |_    /" << std::endl;
        outfile << "                     |-   |" << std::endl;
        outfile << "                     |   =|" << std::endl;
        outfile << "                     |    |" << std::endl;
        outfile << "--------------------/ ,  . \\--------._" << std::endl;
	    outfile.close();
    }
    else{
        std::cerr << "Cannot access the file." << std::endl;
        throw std::invalid_argument("- Error in ShrubberyCreationForm::execute()");
    }
    return;
}