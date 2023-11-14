#include "ClapTrap.hpp"

int main()
{
    ClapTrap	Jack("Jack");
	
	/* Info */
	Jack.setAtkDmg(2);
	std::cout << "\n---------- ClapTrap Jack ----------" << std::endl;
	std::cout << "Hitpoints: " << Jack.getHit() << " ";
	std::cout << "Energy: " << Jack.getEnergy() << " ";
	std::cout << "Attack Damage: " << Jack.getAtkDmg() << " ";
	std::cout << " Status: Active" << std::endl;

	/* Test */
	std::cout << "\nStart attacking...\n" << std::endl;

	Jack.attack("Sharks");
	Jack.attack("Pirates");
	Jack.takeDamage(3);
	Jack.takeDamage(4);
	Jack.beRepaired(10);
	Jack.attack("Dragon");
	Jack.attack("Spirits");
	Jack.attack("Lions");
	Jack.attack("King1");
	Jack.attack("King2");
	Jack.attack("King3");
	Jack.attack("King4");
	Jack.attack("King5");
	Jack.attack("King6");
	Jack.attack("King7");
	Jack.takeDamage(3);
	Jack.beRepaired(10);
	Jack.takeDamage(15);

	std::cout << "\nFights are over..." << std::endl;
    return (0);
}