#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap	tmp("Daniel");
	ScavTrap	Daniel("No name");

	tmp.setAtkDmg(55);
	Daniel = tmp;

	std::cout << "\n--------- ScavTrap Daniel ---------" << std::endl;
	std::cout << "Hitpoints: " << Daniel.getHit() << " ";
	std::cout << "Energy: " << Daniel.getEnergy() << " ";
	std::cout << "Attack Damage: " << Daniel.getAtkDmg() << " ";
	std::cout << "Status: Active" << std::endl;

	std::cout << "\n-- Start attack --\n" << std::endl;

	Daniel.attack("Sharks");
	Daniel.attack("Pirates");
	Daniel.takeDamage(3);
	Daniel.takeDamage(14);
	Daniel.beRepaired(10);
	Daniel.attack("Dragon");
	Daniel.attack("Spirits");
	Daniel.attack("Lions");
	Daniel.attack("Kings");

	std::cout << "\nGuarding time\n" << std::endl;
	Daniel.guardGate();
	std::cout << "\nStop Guarding\n" << std::endl;
    return (0);
}