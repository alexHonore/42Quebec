#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        //Name of class for constructor
        ScavTrap(void);
        ScavTrap(std::string name);
        // Copy of the class from the instance src(new of the current instance)
        ScavTrap(ScavTrap const & src);
        //Tilt before class name for destructor
        ~ScavTrap(void);
        // Assiniation from another instance of the class(update of the current instance) 
        ScavTrap & operator=(ScavTrap const & rhs);
        // using ClapTrap::operator=;
        void guardGate();
        void attack(const std::string& target);
    protected:
        std::string _name;
        unsigned int _hit;
        unsigned int _energy;
        unsigned int _atkDmg;
};

#endif