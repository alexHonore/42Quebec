#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
    public:
        //Name of class for constructor
        DiamondTrap(void);
        DiamondTrap(std::string name);
        // Copy of the class from the instance src(new of the current instance)
        DiamondTrap(DiamondTrap const & src);
        //Tilt before class name for destructor
        ~DiamondTrap(void);
        // Assiniation from another instance of the class(update of the current instance) 
        DiamondTrap & operator=(DiamondTrap const & rhs);
        // using ClapTrap::operator=;
        
        void whoAmI(void);
    private:
        std::string _name;
};

#endif