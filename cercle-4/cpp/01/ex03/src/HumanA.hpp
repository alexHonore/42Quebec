#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
    private:
        Weapon& _weapon;
        std::string _name;
    public:
        //Name of class for constructor
        HumanA(std::string name, Weapon &weapon);
        //Tilt before class name for destructor
        ~HumanA(void);
        void attack();
        std::string getName();
        void setName(std::string name);
        Weapon getWeapon();
        void setWeapon(Weapon &weapon);
};

#endif