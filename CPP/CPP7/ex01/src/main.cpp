#include "../inc/iter.hpp"

void swapCase(char &c)
{
	if (islower(c))
		c -= 32;
	else if (isupper(c))
		c += 32;
}

void doubleInt(int &i)
{
	i += i;
}

int main()
{
	char a[] = "Hello World!";
	int b[] = { 1, 2, 3, 4, 5 };
	char *c = nullptr;

	std::cout << PURPLE << "/////" RESET << " Char Array Before Iter " << PURPLE << "/////" << RESET << std::endl << a << std::endl;
	iter(a, 13, swapCase);
	std::cout << PURPLE << "/////" RESET << " Char Array After Iter " << PURPLE << "/////" << RESET << std::endl << a << std::endl;
	std::cout << std::endl << PURPLE << "/////" RESET << " Int Array Before Iter " << PURPLE << "/////" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i];
		if (i != 4)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
	iter(b, 5, doubleInt);
	std::cout << PURPLE << "/////" RESET << " Int Array After Iter " << PURPLE << "/////" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i];
		if (i != 4)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
	iter(c , 1, swapCase);
	std::cout << std::endl << PURPLE << "/////" RESET << " Iter Partial Array" << PURPLE << "/////" << RESET << std::endl;
	iter(a, 4, swapCase);
	std::cout << a << std::endl;
	return 0;
}