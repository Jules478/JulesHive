#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <cstring>
# include "Weapon.hpp"

typedef std::string str;

class HumanB
{
	private:
			str _name;
			Weapon *_weapon;
	
	public:
			HumanB(str name);
			~HumanB();
			void attack();
			void setWeapon(Weapon &weapon);
};

#endif