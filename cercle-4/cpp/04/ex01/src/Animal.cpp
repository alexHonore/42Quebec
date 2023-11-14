#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal constructor" << std::endl;
}
Animal::Animal(const Animal &src){
    std::cout << "Animal copy constructor" << std::endl;
    *this = src;
}
Animal::Animal(const std::string &name){
    this->type = name;
    std::cout << "Animal constructor of " << this->type << std::endl;
}
Animal::~Animal(){
    std::cout << "Animal destructor" << std::endl;
}
Animal & Animal::operator=(const Animal & rhs){
    std::cout << "Animal copy assignment constructor" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}

const std::string &Animal::getType() const{
    return this->type;
}
void Animal::makeSound() const{
    std::cout << "Looking for a sound to make..." << std::endl;
}