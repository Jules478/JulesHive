#include "DiamondTrap.hpp"

int main()
{
	{
		std::cout << std::endl << "///// Constructor Tests /////" << std::endl;
		DiamondTrap a;
		DiamondTrap b("Aaron");
		DiamondTrap c("Beatrix");
		a = c;
		DiamondTrap d(b);
	}
	{
		std::cout << std::endl << "///// Function Tests /////" << std::endl;
		DiamondTrap a("Clarence");
		DiamondTrap b("Demi");
		DiamondTrap c("Eustace");
		DiamondTrap d("Fiona");

		std::cout << std::endl;

		a.attack("Amelia");
		b.attack("Brent");
		c.attack("Cameron");
		d.attack("Derek");

		a.takeDamage(5);
		b.takeDamage(50);
		c.takeDamage(99);
		d.takeDamage(200);
		a.beRepaired(5);
		b.beRepaired(50);
		c.beRepaired(99);
		d.beRepaired(200);

		a.highFivesGuys();
		b.highFivesGuys();

		c.guardGate();
		d.guardGate();

		for (int i = 0; i < 99; i++)
			c.beRepaired(1);
		
		c.highFivesGuys();
		d.highFivesGuys();

		a.whoAmI();
		b.whoAmI();

		std::cout << std::endl;
	}
	return 0;
}