#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

# define BLUE "\e[0;34m"
# define RESET "\e[0m"

typedef std::string str;

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
			str _name;

	public:
			DiamondTrap();
			DiamondTrap(str name);
			DiamondTrap(const DiamondTrap& guy);
			DiamondTrap& operator=(const DiamondTrap& guy);
			virtual ~DiamondTrap();

			void attack(const str& target);
			void whoAmI(void);
};

#endif