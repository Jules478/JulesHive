#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

# define GREEN "\e[0;32m"
# define RESET "\e[0m"

typedef std::string str;

class ScavTrap : virtual public ClapTrap
{
	private:
			bool _guard;

	public:
			ScavTrap();
			ScavTrap(str name);
			ScavTrap(const ScavTrap& guy);
			ScavTrap& operator=(const ScavTrap& guy);
			~ScavTrap();

			void attack(const str& target);

			void guardGate();
};

#endif