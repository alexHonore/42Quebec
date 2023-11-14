#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie{
    public:
        //Name of class for constructor
        Zombie();
        //Tilt before class name for destructor
        ~Zombie(void);
        void announce(void);
        void setName(std::string name);
    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif