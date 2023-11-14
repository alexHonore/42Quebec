#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    this->brain = new Brain();
    std::cout << "Cat constructor" << std::endl;
}
Cat::Cat(const Cat &src) : Animal("Cat"){
    std::cout << "Cat copy constructor" << std::endl;
    *this = src;
}
Cat::~Cat(){
    delete this->brain;
    std::cout << "Cat destructor" << std::endl;
}
Cat &Cat::operator=(Cat const & rhs){
    std::cout << "Cat copy assignment constructor" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
        this->brain = rhs.brain;
    }
    return *this;
}
void Cat::makeSound() const{
    std::cout << "MEOOWWW!" << std::endl;
}
Brain* Cat::getBrain() const{
    return this->brain;
}