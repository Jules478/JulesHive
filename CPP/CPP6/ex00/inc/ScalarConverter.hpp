#pragma once

#include <iostream>
#include <climits>
#include <cmath>
#include <cfloat>

typedef std::string str;

enum e_type
{
	INVALID,
	PSEUDO,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
			ScalarConverter();
			ScalarConverter(const ScalarConverter& copy);
			ScalarConverter& operator=(const ScalarConverter& copy);
			~ScalarConverter();

	public:
			static void convert(str input);

};

e_type getType(str& input, int len);
void convertPseudo(str& input);
void convertChar(str& input, int len);
void convertInt(str& input);
void convertFloat(str& input);
void convertDouble(str& input);