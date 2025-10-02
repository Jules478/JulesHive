#pragma once

#include <string>

typedef std::string str;

struct Data
{
	public:
			Data();
			Data(const Data& copy);
			Data& operator=(const Data& copy);
			~Data();
			str name;
			int age;
};