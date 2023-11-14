#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
    public:
        //Name of class for constructor
        Weapon(std::string weaponName);
        //Tilt before class name for destructor
        ~Weapon(void);
        std::string const &getType() const;
        void setType(std::string type);
    private:
        std::string _type;
};

#endif