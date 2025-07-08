#pragma once

# include <iostream>
# include "Animal.hpp"

typedef std::string str;

class Dog : public Animal
{
	public:
			Dog();
			Dog(const Dog& copy);
			Dog& operator=(const Dog& copy);
			~Dog();

			void makeSound() const;
};
