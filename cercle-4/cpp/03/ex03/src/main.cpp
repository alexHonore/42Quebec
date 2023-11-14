#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap	Diamond("Daniel");

	Diamond.attack("Pirates");
	Diamond.attack("Kings");
	Diamond.attack("Lions");
	Diamond.beRepaired(10);
	Diamond.takeDamage(100);
	Diamond.guardGate();
	Diamond.highFivesGuys();
	Diamond.whoAmI();
    return (0);
}