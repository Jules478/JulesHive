#include "../inc/Array.hpp"

int main()
{
	Array<int> a;
	Array<int> b;
	Array<char> c;
	Array<const char*> d;

	try
	{
		b = Array<int>(5);
		c = Array<char>(26);
		d = Array<const char*>(3);
	}
	catch (const char* e)
	{
		std::cout << e << std::endl;
		return -1;
	}

	for (unsigned int i = 0; i < b.getSize(); i++)
		b[i] = i * 2;
	for (unsigned int i = 0; i < c.getSize(); i++)
		c[i] = i + 'a';
	d[0] = "Hello";
	d[1] = "World!";
	d[2] = "in C++";

	std::cout << PURPLE << "/////" << RESET << " Accessing Elements " << PURPLE << "/////" << RESET << std::endl << std::endl;
	std::cout << "Array Size: " << GREEN << a.getSize() << RESET << std::endl;	
	try { for (unsigned int i = 0; i < 2; i++)
		std::cout << "Index " << RED << i << RESET << ": " << GREEN << a[i] << RESET << std::endl; }
	catch (std::exception &e) { std::cout << RESET << e.what() << std::endl; }
	std::cout << std::endl;
	std::cout << "Array Size: " << GREEN << b.getSize() << RESET << std::endl;
	try { for (unsigned int i = 0; i < b.getSize(); i++)
		std::cout << "Index " << RED << i << RESET << ": " << GREEN << b[i] << RESET << std::endl; }
	catch (std::exception &e) { std::cout << RESET << e.what() << std::endl; }
	std::cout << std::endl;
	std::cout << "Array Size: " << GREEN << c.getSize() << RESET << std::endl;
	try { for (unsigned int i = 0; i < c.getSize() + 1; i++)
		std::cout << "Index " << RED << i << RESET << ": " << GREEN << c[i] << RESET << std::endl; }
	catch (std::exception &e) { std::cout << RESET << e.what() << std::endl; }
	std::cout << std::endl;
	std::cout << "Array Size: " << GREEN << d.getSize() << RESET << std::endl;
	try { for (unsigned int i = 0; i < d.getSize(); i++)
		std::cout << "Index " << RED << i << RESET << ": " << GREEN << d[i] << RESET << std::endl; }
	catch (std::exception &e) { std::cout << RESET << e.what() << std::endl; }
	std::cout << std::endl;

	{
		std::cout << PURPLE << "/////" << RESET << " Copy Constructors " << PURPLE << "/////" << RESET << std::endl << std::endl;
		Array<int> a(5);
		Array<int> b(10);
		
		for (unsigned int i = 0; i < a.getSize(); i++)
			a[i] = i;
		for (unsigned int i = 0; i < b.getSize(); i++)
			b[i] = i * 2;
		
		Array<int> c(b);
		std::cout << PURPLE << "///" << RESET << " Array a " << PURPLE << "///" << RESET << std::endl;
		try { for (unsigned int i = 0; i < a.getSize(); i++)
			std::cout << "Index " << RED << i << RESET << ": " << GREEN << a[i] << RESET << std::endl; }
		catch (std::exception &e) { std::cout << RESET << e.what() << std::endl; }
		std::cout << std::endl;
		std::cout << PURPLE << "///" << RESET << " Array b " << PURPLE << "///" << RESET << std::endl;
		try { for (unsigned int i = 0; i < b.getSize(); i++)
			std::cout << "Index " << RED << i << RESET << ": " << GREEN << b[i] << RESET << std::endl; }
		catch (std::exception &e) { std::cout << RESET << e.what() << std::endl; }
		std::cout << std::endl;

		std::cout << PURPLE << "///" << RESET << " Assign Array a to Array b " << PURPLE << "///" << RESET << std::endl;
		b = a;
		try { for (unsigned int i = 0; i < b.getSize(); i++)
			std::cout << "Index " << RED << i << RESET << ": " << GREEN << b[i] << RESET << std::endl; }
		catch (std::exception &e) { std::cout << RESET << e.what() << std::endl; }
		std::cout << std::endl;

		std::cout << PURPLE << "///" << RESET << " Array c (copied from orignal b) " << PURPLE << "///" << RESET << std::endl;
		try { for (unsigned int i = 0; i < c.getSize(); i++)
			std::cout << "Index " << RED << i << RESET << ": " << GREEN << c[i] << RESET << std::endl; }
		catch (std::exception &e) { std::cout << RESET << e.what() << std::endl; }
		std::cout << std::endl;
	}
}
