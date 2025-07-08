#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>
# include <iomanip>
# include "Contact.hpp"

typedef std::string str;

class	PhoneBook
{
	private:
			Contact list[8];
			int	current_index;
			int current_size;
			
	public:
			PhoneBook();
			~PhoneBook();
			void addContact();
			void searchContact();
			void findIndex(int i);
};

str get_input(void);

#endif