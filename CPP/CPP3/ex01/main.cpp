#include "ScavTrap.hpp"

int main()
{
	{
		std::cout << std::endl << "///// Constructor Tests /////" << std::endl;
		ScavTrap a;
		ScavTrap b("Alan");
		ScavTrap c("Belinda");
		a = c;
		ScavTrap d(b);
	}
	{
		std::cout << std::endl << "///// Function Tests /////" << std::endl;
		ScavTrap a("Charlie");
		ScavTrap b("Davina");
		ScavTrap c("Eric");
		ScavTrap d("Felicity");

		std::cout << std::endl;

		a.attack("Alexa");
		b.attack("Brian");
		c.attack("Cindy");
		d.attack("Darren");

		a.takeDamage(5);
		b.takeDamage(50);
		c.takeDamage(99);
		d.takeDamage(200);
		a.beRepaired(5);
		b.beRepaired(50);
		c.beRepaired(99);
		d.beRepaired(200);

		a.guardGate();
		b.guardGate();
		c = a;
		c.guardGate();
		d.guardGate();
		b.takeDamage(150);
		b.guardGate();
		for (int i = 0; i < 49; i++)
			a.attack("it's self esteem");

		std::cout << std::endl;
	}
	return 0;
}