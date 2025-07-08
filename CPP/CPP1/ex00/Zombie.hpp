#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

typedef std::string str;

class Zombie
{
	private:
			str _name;
	
	public:
			Zombie();
			~Zombie();
			void announce( void );
			void setName(str name);
};

Zombie* newZombie(str name);
void randomChump(str name);

#endif