#include "../inc/ScalarConverter.hpp"

void convertPseudo(str& input)
{
	if (input == "nan" || input == "nanf")
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: nanf" << std::endl << "double: nan" << std::endl;
	else if (input == "+inf" || input == "+inff")
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: +inff" << std::endl << "double: +inf" << std::endl;
	else if (input == "-inf" || input == "-inff")
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: -inff" << std::endl << "double: -inf" << std::endl;
}

void convertChar(str& input, int len)
{
	int num;
	float fl;
	double db;

	if (len == 1)
	{
		if (isprint(input[0]))
			std::cout << "char: " << input << std::endl;
		else
			std::cout << "char: not displayable" << std::endl;
		num = static_cast<int>(input[0]);
		fl = static_cast<float>(input[0]);
		db = static_cast<double>(input[0]);
	}
	else
	{
		if (isprint(input[1]))
			std::cout << "char: " << input[1] << std::endl;
		else
			std::cout << "char: not displayable" << std::endl;
		num = static_cast<int>(input[1]);
		fl = static_cast<float>(input[1]);
		db = static_cast<double>(input[1]);
	}
	std::cout << "int: " << num << std::endl << "float: " << fl << ".0f" << std::endl << "double: " << db << ".0" << std::endl;
}

void convertInt(str& input)
{
	long convert;
	try { convert = std::stol(input); }
	catch ( const std::out_of_range& e )
	{
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: impossible" << std::endl << "double: impossible" << std::endl;
		return;
	}
	std::cout << "char: ";
	if (convert < 0 || convert > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(convert))
			std::cout << static_cast<char>(convert) << std::endl;
		else
			std::cout << "not displayable" << std::endl;
	}
	std::cout << "int: ";
	if (convert < INT_MIN || convert > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(convert) << std::endl;
	if (convert < FLOAT_MIN || convert > INT_MAX)
		std::cout << "impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(convert) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(convert) << ".0" << std::endl;
}

void convertFloat(str& input)
{
	float	fl;
	
	try { fl = std::atof(input.c_str()); }
	catch ( const std::out_of_range& e )
	{
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: impossible" << std::endl << "double: impossible" << std::endl;
		return;
	}
	
	bool tolerance = std::fabs(fl - static_cast<int>(fl)) < 0.0000000000001;

	std::cout << "char: ";
	if (fl < 0 || fl > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(fl))
			std::cout << "'" << static_cast<char>(fl) << "'" << std::endl;
		else 
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (static_cast<long>(fl) < INT_MIN || static_cast<long>(fl) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(fl) << std::endl;
	std::cout << "float: ";
	if (static_cast<long>(fl) < FLT_MIN || static_cast<long>(fl) > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << fl << (tolerance ? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(fl) << (tolerance ? ".0" : "") << std::endl;
}

void convertDouble(str& input)
{
	double	dub;
	
	try { dub = std::atof(input.c_str()); }
	catch ( const std::out_of_range& e )
	{
		std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl << "float: impossible" << std::endl << "double: impossible" << std::endl;
		return;
	}
	
	bool tolerance = std::fabs(dub - static_cast<int>(dub)) < 0.0000000000001;

	std::cout << "char: ";
	if (dub < 0 || dub > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(dub))
			std::cout << "'" << static_cast<char>(dub) << "'" << std::endl;
		else 
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (static_cast<long>(dub) < INT_MIN || static_cast<long>(dub) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(dub) << std::endl;
	std::cout << "float: ";
	else
		std::cout << dub << (tolerance ? ".0f" : ".f") << std::endl;
	std::cout << "double: " << static_cast<double>(dub) << (tolerance ? ".0" : "") << std::endl;
}

static bool isPseudo(str& input)
{
	if (input == "+inff" || input == "-inff" || input == "nanf" || input == "+inf" || input == "-inf" || input == "nan")
		return true;
	return false;
}

static bool isChar(str& input, int len)
{
	if (len == 1 && !isdigit(input[0]))
		return true;
	if (len == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	return false;
}

static bool isInt(str& input, int len)
{
	bool sign = false;
	if (input[0] == '+' || input[0] == '-')
		sign = true;
	for (int i = 0 + sign; i < len; i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

static bool isFloat(str& input, int len, int d)
{
	for (int i = d - 1; i >= 0; i--)
	{
		if (!isdigit(input[i]) && i != 0)
			return false;
		if (!isdigit(input[i]) && i == 0 && input[i] != '+' && input[i] != '-')
			return false;
	}
	for (int i = d + 1; i < len; i++)
	{
		if (!isdigit(input[i]) && input[i] != 'f')
			return false;
		if (input[i] == 'f' && i != len - 1)
			return false;
	}
	return true;
}

e_type getType(str& input, int len)
{
	size_t d = input.find(".");
	size_t f = input.find("f");

	if (d == str::npos)
	{
		if (isPseudo(input))
			return PSEUDO;
		if (isChar(input, len))
			return CHAR;
		if (isInt(input, len))
			return INT;
	}
	if (f != str::npos && d != str::npos)
	{
		if (isFloat(input, len, d))
			return FLOAT;
	}
	if (f == str::npos && d != str::npos)
		return DOUBLE;
	return INVALID;
}
