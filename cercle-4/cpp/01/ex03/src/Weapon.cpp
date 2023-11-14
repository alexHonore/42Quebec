#include "Weapon.hpp"

Weapon::Weapon(std::string weaponName) : _type(weaponName){
    return;
}
Weapon::~Weapon(void){
    return;
}
std::string const &Weapon::getType() const{
    return this->_type;
}

void Weapon::setType(std::string type){
    this->_type = type;
}
