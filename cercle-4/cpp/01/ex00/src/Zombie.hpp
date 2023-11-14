#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie{
    public:
        //Name of class for constructor
        Zombie(std::string name);
        //Tilt before class name for destructor
        ~Zombie(void);
        void announce(void);
    private:
        std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif