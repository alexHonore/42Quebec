#ifndef FragTrap_HPP
# define FragTrap_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        //Name of class for constructor
        FragTrap(void);
        FragTrap(std::string name);
        // Copy of the class from the instance src(new of the current instance)
        FragTrap(FragTrap const & src);
        //Tilt before class name for destructor
        ~FragTrap(void);
        // Assiniation from another instance of the class(update of the current instance) 
        FragTrap & operator=(FragTrap const & rhs);
        // using ClapTrap::operator=;
        
        void highFivesGuys(void);
    protected:
        std::string _name;
        unsigned int _hit;
        unsigned int _energy;
        unsigned int _atkDmg;
};

#endif