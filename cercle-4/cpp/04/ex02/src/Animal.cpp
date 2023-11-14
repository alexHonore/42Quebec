#include "Animal.hpp"

Animal::~Animal(){
    std::cout << "Animal destructor" << std::endl;
}

const std::string &Animal::getType() const{
    return this->type;
}