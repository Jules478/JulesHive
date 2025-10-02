#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0m"

typedef std::string str;

class Serializer
{
	private:
			Serializer();
			Serializer(const Serializer& copy);
			Serializer& operator=(const Serializer& copy);
			~Serializer();

	public:
			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
};