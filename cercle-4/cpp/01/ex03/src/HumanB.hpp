#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{
    private:
        Weapon* _weapon;
        std::string _name;
    public:
        //Name of class for constructor
        HumanB(std::string name);
        //Tilt before class name for destructor
        ~HumanB(void);
        void attack() const;
        std::string getName();
        void setName(std::string name);
        Weapon* getWeapon();
        void setWeapon(Weapon &weapon);
};

#endif
