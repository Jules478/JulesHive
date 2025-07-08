#include "Phonebook.hpp"

int main()
{
	str input;

	PhoneBook phonebook;

#ifdef NICE
	system("clear");
#endif
	while (1)
	{
		std::cout << "Please enter a command: (ADD) (SEARCH) (EXIT)" << std::endl;
		input = get_input();
		if (input == "ADD")
		{
#ifdef NICE
	system("clear");
#endif
			std::cout << "New Contact" << std::endl;
			phonebook.addContact();
#ifdef NICE
	system("clear");
#endif
		}
		else if (input == "SEARCH")
		{
#ifdef NICE
	system("clear");
#endif
			phonebook.searchContact();
		}
		else if (input == "EXIT")
		{
#ifdef NICE
	system("clear");
#endif
			break ;
		}
		else
		{
#ifdef NICE
	system("clear");
#endif
			std::cout << "Invalid Command!" << std::endl;
		}
	}
	return 0;
}