#pragma once

# include <iostream>
# include "Animal.hpp"

typedef std::string str;

class Cat : public Animal
{
	public:
			Cat();
			Cat(const Cat& copy);
			Cat& operator=(const Cat& copy);
			~Cat();

			void makeSound() const;
};
