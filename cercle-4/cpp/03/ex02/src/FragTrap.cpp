#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(){
    std::cout << "Default Frag Constructor called" << std::endl;
    this->setName("Default");
	this->setHit(100);
	this->setEnergy(100);
	this->setAtkDmg(30);
    return;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "Frag Constructor " << name << " called." << std::endl;
    this->setName(name);
	this->setHit(100);
	this->setEnergy(100);
	this->setAtkDmg(30);
    return;
}
FragTrap::~FragTrap(void){
    std::cout << "Frag Destructor " << this->getName() << " called." << std::endl;
    return;
}
FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src){
    std::cout << "Frag Copy constructor called" << std::endl;
    return;
}
FragTrap &FragTrap::operator=(FragTrap const & rhs){
    std::cout << "Frag Copy assignment operator called" << std::endl;
    if (this != &rhs){
        this->setName(rhs.getName());
        this->setHit(rhs.getHit());
        this->setEnergy(rhs.getEnergy());
        this->setAtkDmg(rhs.getAtkDmg());
    }
    return *this;
}
void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << this->getName() << " wants a high five!!" << std::endl;
}
