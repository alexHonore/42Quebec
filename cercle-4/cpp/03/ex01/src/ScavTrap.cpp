#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(){
    std::cout << "Default Scav Constructor called" << std::endl;
    return;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "Scav Constructor " << name << " called." << std::endl;
    return;
}
ScavTrap::~ScavTrap(void){
    std::cout << "Scav Destructor " << this->getName() << " called." << std::endl;
    return;
}
ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src){
    std::cout << "Scav Copy constructor called" << std::endl;
    return;
}
void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate Keeper mode" << std::endl;
}
void ScavTrap::attack(const std::string& target){
    if (this->getEnergy() <= 1){
        std::cout << this->getName() << "don't have enough energy to attack" << std::endl;
    }
    else{
        this->setEnergy(this->getEnergy() - 1);
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAtkDmg() << " points of damage!" << std::endl;
    }
}