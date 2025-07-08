#pragma once

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

typedef std::string str;

class Dog : public Animal
{
	private:
			Brain* _brain;
	public:
			Dog();
			Dog(const Dog& copy);
			Dog& operator=(const Dog& copy);
			~Dog();

			void makeSound() const;
};
