#include "Zombie.hpp"

int main()
{
    Zombie zombie("Locallll");
    Zombie* zombie1 = newZombie("zombie1");
    zombie.announce();
    zombie1->announce();
    randomChump("zombie2");
    delete zombie1;
    return (0);
}