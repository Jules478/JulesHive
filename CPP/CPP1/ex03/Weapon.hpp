#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <cstring>

typedef std::string str;

class Weapon
{
	private:
			str _type;
	
	public:
			Weapon(str type);
			~Weapon();
			const str &getType() const;
			void setType(str type);
};

#endif