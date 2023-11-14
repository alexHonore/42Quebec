#include "Zombie.hpp"

int main()
{
    Zombie* zombie1 = zombieHorde(42, "brain");
    delete [] zombie1;
    return (0);
}