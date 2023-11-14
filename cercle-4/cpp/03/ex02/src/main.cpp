#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap	temp("Daniel");
	ScavTrap	Daniel("No name");

	/* Assignment check */
	temp.setAtkDmg(55);
	Daniel = temp;

	/* Info */
	std::cout << "\n---------- ScavTrap Daniel ----------" << std::endl;
	std::cout << "Hitpoints: " << Daniel.getHit() << " ";
	std::cout << "Energy: " << Daniel.getEnergy() << " ";
	std::cout << "Attack Damage: " << Daniel.getAtkDmg() << " ";
	std::cout << "Status: Active" << std::endl;

	/* Test */
	std::cout << "\nStart attacking...\n" << std::endl;

	Daniel.attack("Sharks");
	Daniel.attack("Pirates");
	Daniel.takeDamage(3);
	Daniel.takeDamage(14);
	Daniel.beRepaired(10);
	Daniel.attack("Dragon");
	Daniel.attack("Spirits");
	Daniel.attack("Lions");
	Daniel.attack("Kings");

	std::cout << "\nFights are over. Guarding time...\n" << std::endl;
	Daniel.guardGate();
	std::cout << "\nGuareded too much...Enough!\n" << std::endl;
    return (0);
}