#include "FragTrap.hpp"

int main()
{
	{
		std::cout << std::endl << "///// Constructor Tests /////" << std::endl;
		FragTrap a;
		FragTrap b("Arnold");
		FragTrap c("Brandy");
		a = c;
		FragTrap d(b);
	}
	{
		std::cout << std::endl << "///// Function Tests /////" << std::endl;
		FragTrap a("Calvin");
		FragTrap b("Dominique");
		FragTrap c("Ed");
		FragTrap d("Florence");

		std::cout << std::endl;

		a.attack("Amy");
		b.attack("Bert");
		c.attack("Coleen");
		d.attack("Damien");

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

		for (int i = 0; i < 99; i++)
			c.beRepaired(1);
		
		c.highFivesGuys();
		d.highFivesGuys();

		std::cout << std::endl;
	}
	return 0;
}