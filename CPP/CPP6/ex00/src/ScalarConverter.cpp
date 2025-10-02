#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(str input)
{
	int len = input.length();
	e_type type = getType(input, len);

	switch (type)
	{
		case PSEUDO:
		{
			convertPseudo(input);
			break;
		}
		case CHAR:
		{
			convertChar(input, len);
			break;
		}
		case INT:
		{
			convertInt(input);
			break;
		}
		case FLOAT:
		{
			convertFloat(input);
			break;
		}
		case DOUBLE:
		{
			convertDouble(input);
			break;
		}
		default:
		{
			std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: impossible" << std::endl << "double: impossible" << std::endl;
			break;
		}
	}
}
