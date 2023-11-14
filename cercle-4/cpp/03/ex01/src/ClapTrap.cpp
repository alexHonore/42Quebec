#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
    std::cout << "Default Constructor called" << std::endl;
    this->_hit = 100;
    this->_energy = 50;
    this->_atkDmg = 20;
    return;
}
ClapTrap::ClapTrap(std::string name){
    std::cout << "Constructor " << name << " called." << std::endl;
    this->_name = name;
    this->_hit = 100;
    this->_energy = 50;
    this->_atkDmg = 20;
    return;
}
ClapTrap::~ClapTrap(void){
    std::cout << "Destructor " << this->getName() << " called." << std::endl;
    return;
}
ClapTrap::ClapTrap(ClapTrap const & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}
std::string ClapTrap::getName()const{
    return this->_name;
}
unsigned int ClapTrap::getHit()const{
    return this->_hit;
}
unsigned int ClapTrap::getEnergy()const{
    return this->_energy;
}
unsigned int ClapTrap::getAtkDmg()const{
    return this->_atkDmg;
}
void ClapTrap::setName(std::string name){
    this->_name = name;
}
void ClapTrap::setHit(unsigned int hit){
    this->_hit = hit;
}
void ClapTrap::setEnergy(unsigned int energy){
    this->_energy = energy;
}
void ClapTrap::setAtkDmg(unsigned int atkDmg){
    this->_atkDmg = atkDmg;
}
ClapTrap &ClapTrap::operator=(ClapTrap const & rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs){
        this->setName(rhs.getName());
        this->setHit(rhs.getHit());
        this->setEnergy(rhs.getEnergy());
        this->setAtkDmg(rhs.getAtkDmg());
    }
    return *this;
}

void ClapTrap::attack(const std::string& target){
    if (this->getEnergy() <= 1){
        std::cout << this->getName() << "don't have enough energy to attack" << std::endl;
    }
    else{
        this->setEnergy(this->getEnergy() - 1);
        std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAtkDmg() << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->getHit() <= amount){
        std::cout << this->getName() << " is KO!" << std::endl;
        this->setHit(0);
    }
    else
        this->setHit(this->getHit() - amount);
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->getEnergy() <= 1){
        std::cout << this->getName() << "don't have enough energy to repair" << std::endl;
    }
    else{
        this->setEnergy(this->getEnergy() - 1);
        this->setHit(this->getHit() + amount);
        std::cout << "ClapTrap " << this->getName() << " gained " << amount << " hit points!" << std::endl;
    }
}
