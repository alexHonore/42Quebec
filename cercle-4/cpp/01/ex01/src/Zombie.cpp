#include "Zombie.hpp"

Zombie::Zombie(void){
    return;
}

Zombie::~Zombie(void){
    std::cout << this->_name << ": Deleted" << std::endl;
    return;
}

void Zombie::announce(void){
    std::cout << this->_name << ": BaiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
    this->_name = name;
}
