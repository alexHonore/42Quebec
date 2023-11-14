#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name){
    return;
}
HumanA::~HumanA(void){
    return;
}
std::string HumanA::getName(){
    return this->_name;
}
void HumanA::setName(std::string name){
    this->_name = name;
}
Weapon HumanA::getWeapon(){
    return this->_weapon;
}
void HumanA::setWeapon(Weapon &weapon){
    this->_weapon = weapon;
}
    
void HumanA::attack(){
    std::cout << this->_name << " attacks with their " << this->_weapon.getType();
    std::cout << std::endl;
}
