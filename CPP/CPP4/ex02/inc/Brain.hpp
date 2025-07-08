#pragma once

#include <iostream>

#define CYAN "\e[0;36m"
#define RESET "\e[0m"

typedef std::string str;

class Brain
{
	private:
			str _ideas[100];

	public:
			Brain();
			Brain(const Brain& copy);
			Brain& operator=(const Brain& copy);
			~Brain();

};