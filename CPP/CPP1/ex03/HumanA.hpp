#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <cstring>
# include "Weapon.hpp"

typedef std::string str;

class HumanA
{
	private:
			str _name;
			Weapon &_weapon;
	
	public:
			HumanA(str name, Weapon &weapon);
			~HumanA();
			void attack();
};

#endif