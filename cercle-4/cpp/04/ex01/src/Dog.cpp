#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
    this->brain = new Brain();
    std::cout << "Dog constructor" << std::endl;
}
Dog::Dog(const Dog &src) : Animal("Dog"){
    std::cout << "Dog copy constructor" << std::endl;
    *this = src;
}
Dog::~Dog(){
    delete this->brain;
    std::cout << "Dog destructor" << std::endl;
}
Dog &Dog::operator=(Dog const & rhs){
    std::cout << "Dog copy assignment constructor" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
        this->brain = rhs.brain;
    }
    return *this;
}
void Dog::makeSound() const{
    std::cout << "WOOOOF!" << std::endl;
}
Brain* Dog::getBrain() const{
    return this->brain;
}