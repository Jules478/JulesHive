#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

typedef std::string str;

class ClapTrap
{
	protected:
			str _name;
			int	_hp;
			int _ep;
			int _dmg;
	
	public:
			ClapTrap();
			ClapTrap(str name);
			ClapTrap(const ClapTrap& guy);
			ClapTrap& operator=(const ClapTrap& guy);
			~ClapTrap();

			void attack(const str& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);

};

#endif