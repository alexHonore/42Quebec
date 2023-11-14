#include "Zombie.hpp"

void randomChump(std::string name){
    // create a zombie & give it a name
    Zombie z(name);
    z.announce();
}