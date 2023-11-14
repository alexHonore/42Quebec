#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructor" << std::endl;
}
Cat::Cat(const Cat &src){
    this->type = "Cat";
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
Animal &Cat::operator=(Animal const & rhs){
    const Cat *cat = dynamic_cast<const Cat*>(&rhs);
    std::cout << "Cat copy assignment constructor" << std::endl;
    if (this != cat){
        this->type = cat->type;
        this->brain = cat->brain;
    }
    return *this;
}
void Cat::makeSound() const{
    std::cout << "MEOOWWW!" << std::endl;
}
Brain* Cat::getBrain() const{
    return this->brain;
}