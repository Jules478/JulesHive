#include "ClapTrap.hpp"

int main()
{
	{
		std::cout << std::endl;
		std::cout << "///// Constructor Tests //////" << std::endl;
		ClapTrap a;
		ClapTrap b("Andy");
		ClapTrap c("Betty");
		c = a;
		ClapTrap d(b);
	}
	{
		std::cout << std::endl;
		std::cout << "///// Attack Tests //////" << std::endl;
		ClapTrap a("Carl");
		ClapTrap b("Doris");
		a.attack("Doris");
		for (int i = 0; i < 12; i++)
			b.attack("you");
	}
	{
		std::cout << std::endl;
		std::cout << "///// Damage Tests //////" << std::endl;
		ClapTrap a("Ernie");
		ClapTrap b("Fern");
		a.takeDamage(5);
		b.takeDamage(0);
		a.takeDamage(5);
		b.takeDamage(9);
		a.takeDamage(1);
		b.takeDamage(0);
		a.attack("someone");
		b.attack("someone");
	}
	{
		std::cout << std::endl;
		std::cout << "///// Repair Tests //////" << std::endl;
		ClapTrap a("Gary");
		ClapTrap b("Helen");
		a.takeDamage(9);
		b.takeDamage(9);
		a.beRepaired(4);
		for (int i = 0; i < 11; i++)
			b.beRepaired(1);
		a.takeDamage(5);
		a.takeDamage(1);
		b.takeDamage(9);
		b.takeDamage(1);
	}
	{
		std::cout << std::endl;
		std::cout << "///// Energy Tests //////" << std::endl;
		ClapTrap a("Ivan");
		ClapTrap b("Jessica");
		for (int i = 0; i < 10; i++)
			a.attack("no one");
		a.beRepaired(1);
		a.takeDamage(1);
		for (int i = 0; i < 9; i++)
			b.takeDamage(1);
		for (int i = 0; i < 10; i++)
			b.beRepaired(1);
		b.attack("itself");
	}
	return 0;
}