#pragma once

# include <iostream>
# include "WrongAnimal.hpp"

typedef std::string str;

class WrongCat : public WrongAnimal
{
	public:
			WrongCat();
			WrongCat(const WrongCat& copy);
			WrongCat& operator=(const WrongCat& copy);
			~WrongCat();

			void makeSound() const;
};
