#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

typedef std::string str;

# define RED "\e[0;31m"
# define RESET "\e[0m"

class FragTrap : public ClapTrap
{
	public:
			FragTrap();
			FragTrap(str name);
			FragTrap(const FragTrap& guy);
			FragTrap& operator=(const FragTrap& guy);
			~FragTrap();

			void highFivesGuys(void);
};

#endif