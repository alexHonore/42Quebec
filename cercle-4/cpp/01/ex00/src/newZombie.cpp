#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    // create zombie and give its name & return it
    Zombie* z = new Zombie(name);
    return z;
}