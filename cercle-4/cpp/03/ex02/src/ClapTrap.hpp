#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    public:
        //Name of class for constructor
        ClapTrap(void);
        ClapTrap(std::string name);
        // Copy of the class from the instance src(new of the current instance)
        ClapTrap(ClapTrap const & src);
        //Tilt before class name for destructor
        ~ClapTrap(void);
        // Assiniation from another instance of the class(update of the current instance) 
        ClapTrap & operator=(ClapTrap const & rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName()const;
        unsigned int getHit()const;
        unsigned int getEnergy()const;
        unsigned int getAtkDmg()const;
        void setName(std::string name);
        void setHit(unsigned int hit);
        void setEnergy(unsigned int energy);
        void setAtkDmg(unsigned int atkDmg);
    private:
        std::string _name;
        unsigned int _hit;
        unsigned int _energy;
        unsigned int _atkDmg;
};

#endif