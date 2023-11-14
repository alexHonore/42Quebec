#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
    return;
}
HumanB::~HumanB(void){
    return;
}
std::string HumanB::getName(){
    return this->_name;
}
void HumanB::setName(std::string name){
    this->_name = name;
}
Weapon* HumanB::getWeapon(){
    return this->_weapon;
}
void HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
}
void HumanB::attack() const{
    if (this->_weapon->getType().empty())
        this->_weapon->setType("bare hands");
    std::cout << this->_name << " attacks with their " << this->_weapon->getType();
    std::cout << std::endl;
}
