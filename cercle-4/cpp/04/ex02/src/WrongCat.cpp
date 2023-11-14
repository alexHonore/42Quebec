#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout << "WrongCat constructor" << std::endl;
}
WrongCat::WrongCat(const WrongCat &src){
    this->type = "WrongCat";
    std::cout << "WrongCat copy constructor" << std::endl;
    *this = src;
}
WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor" << std::endl;
}
WrongCat &WrongCat::operator=(WrongCat const & rhs){
    std::cout << "WrongCat copy assignment constructor" << std::endl;
    if (this != &rhs){
        this->type = rhs.type;
    }
    return *this;
}
void WrongCat::makeSound() const{
    std::cout << "Wrong MEOOWWW!" << std::endl;
}