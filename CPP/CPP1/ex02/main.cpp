#include <iostream>

typedef std::string str;

int main()
{
	str string = "HI THIS IS BRAIN";
	str *stringPTR = &string;
	str &stringREF = string;

	std::cout << &string << " : Memory Address of String" << std::endl;
	std::cout << stringPTR << " : Memory Address Held by String Pointer" << std::endl;
	std::cout << &stringREF << " : Memory Address Held by String Reference" << std::endl;

	std::cout << std::endl;

	std::cout << string << " : Value of String" << std::endl;
	std::cout << *stringPTR << " : Value Pointed to by String Pointer" << std::endl;
	std::cout << stringREF << " : Value Referenced by String Reference" << std::endl;

	return 0;
}