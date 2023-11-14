#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
    return;
}

Zombie::~Zombie(void){
    std::cout << this->_name << ": Deleted" << std::endl;
    return;
}

void Zombie::announce(void){
    std::cout << this->_name << ": BaiiiiiiinnnzzzZ..." << std::endl;
}

