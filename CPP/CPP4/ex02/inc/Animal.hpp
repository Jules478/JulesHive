#pragma once

# include <iostream>

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define RESET "\e[0m"

typedef std::string str;

class Animal
{
	protected:
			str _type;
	public:
			Animal();
			Animal(const Animal& copy);
			Animal& operator=(const Animal& copy);
			virtual ~Animal();

			virtual void makeSound() const = 0;

			str getType() const;
};
