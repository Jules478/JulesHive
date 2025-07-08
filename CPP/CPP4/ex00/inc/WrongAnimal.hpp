#pragma once

# include <iostream>

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define RESET "\e[0m"

typedef std::string str;

class WrongAnimal
{
	protected:
			str _type;
	public:
			WrongAnimal();
			WrongAnimal(const WrongAnimal& copy);
			WrongAnimal& operator=(const WrongAnimal& copy);
			virtual ~WrongAnimal();

			void makeSound() const;

			str getType() const;
};
