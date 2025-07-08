#pragma once

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

typedef std::string str;

class Cat : public Animal
{
	private:
			Brain* _brain;

	public:
			Cat();
			Cat(const Cat& copy);
			Cat& operator=(const Cat& copy);
			~Cat();

			void makeSound() const;
};
