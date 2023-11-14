#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap(){
    std::cout << "Default Diamond Constructor called" << std::endl;
    this->_name = "Default";
	ScavTrap::setName(_name  + "_clap_name");
    ScavTrap::setHit(FragTrap::getHit());
    ScavTrap::setEnergy(ScavTrap::getEnergy());
    ScavTrap::setAtkDmg(FragTrap::getAtkDmg());
    return;
}
DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name){
    std::cout << "Diamond Constructor " << name << " called." << std::endl;
    this->_name = name;
	ScavTrap::setName(name  + "_clap_name");
    ScavTrap::setHit(FragTrap::getHit());
    ScavTrap::setEnergy(ScavTrap::getEnergy());
    ScavTrap::setAtkDmg(FragTrap::getAtkDmg());
    return;
}
DiamondTrap::~DiamondTrap(void){
    std::cout << "Diamond Destructor " << this->_name << " called." << std::endl;
    return;
}
DiamondTrap::DiamondTrap(DiamondTrap const & src) : FragTrap(), ScavTrap(src){
    std::cout << "Diamond Copy constructor called" << std::endl;
    return;
}
DiamondTrap &DiamondTrap::operator=(DiamondTrap const & rhs){
    std::cout << "Diamond Copy assignment operator called" << std::endl;
    if (this != &rhs){
        ScavTrap::setName(rhs.ScavTrap::getName());
        ScavTrap::setHit(rhs.ScavTrap::getHit());
        ScavTrap::setEnergy(rhs.ScavTrap::getEnergy());
        ScavTrap::setAtkDmg(rhs.ScavTrap::getAtkDmg());
    }
    return *this;
}
void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap " << this->_name << " DT name: " << this->_name  << std::endl;
    std::cout << "DiamondTrap " << this->_name << " CT name: " << ScavTrap::getName()  << std::endl;
}
