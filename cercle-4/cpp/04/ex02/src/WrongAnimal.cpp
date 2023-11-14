#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal constructor" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &src){
    std::cout << "WrongAnimal copy constructor" << std::endl;
    *this = src;
}
WrongAnimal::WrongAnimal(const std::string &name){
    this->type = name;
    std::cout << "WrongAnimal constructor of " << this->type << std::endl;
}
WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor" << std::endl;
}
WrongAnimal & WrongAnimal::operator=(const WrongAnimal & rhs){
    std::cout << "WrongAnimal copy assignment constructor" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}
const std::string &WrongAnimal::getType() const{
    return this->type;
}
void WrongAnimal::makeSound() const{
    std::cout << "Looking for a wrong sound to make..." << std::endl;
}