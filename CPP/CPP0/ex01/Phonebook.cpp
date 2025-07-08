#include <iostream>
#include "Phonebook.hpp"

PhoneBook::PhoneBook() : current_index(0), current_size(0)
{
}

PhoneBook::~PhoneBook()
{
}

str get_input()
{
	str input;

	input = "";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cin.clear();
		exit(1);
	}
	if (input.empty())
		return "";
	return input;
}

void PhoneBook::addContact()
{
	str input = "";

	std::cout << "Enter forename: ";
	input = get_input();
	while (input.empty())
	{
		std::cout << "Forename required!" << std::endl;
		std::cout << "Enter forename: ";
		input = get_input();
	}
	list[current_index].setFore(input);

	input = "";
	std::cout << "Enter surname: ";
	input = get_input();
	while (input.empty())
	{
		std::cout << "Surname required!" << std::endl;
		std::cout << "Enter surname: ";
		input = get_input();
	}
	list[current_index].setSur(input);

	input = "";
	std::cout << "Enter nickname: ";
	input = get_input();
	while (input.empty())
	{
		std::cout << "Nickname required!" << std::endl;
		std::cout << "Enter nickname: ";
		input = get_input();
	}
	list[current_index].setNick(input);

	input = "";
	std::cout << "Enter phone number: ";
	input = get_input();
	while (input.empty())
	{
		std::cout << "Phone number required!" << std::endl;
		std::cout << "Enter phone number: ";
		input = get_input();
	}
	list[current_index].setPhone(input);

	input = "";
	std::cout << "Enter secret: ";
	input = get_input();
	while (input.empty())
	{
		std::cout << "Darkest secret required!" << std::endl;
		std::cout << "Enter secret: ";
		input = get_input();
	}
	list[current_index].setSecret(input);

	if (current_size != 8)
		current_size++;
	current_index = (current_index + 1) % 8;
}

void PhoneBook::findIndex(int i)
{
#ifdef NICE
	system("clear");
#endif
	std::cout << "Contact " << i + 1 << std::endl;

}

void PhoneBook::searchContact()
{
	str input = "";

	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "Forename" << " | ";
	std::cout << std::setw(10) << "Surname" << " | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < current_size; i++)
	{
		str fore = list[i].getFore();
		if (fore.length() > 9)
			fore = fore.substr(0, 9) + ".";
		str sur = list[i].getSur();
		if (sur.length() > 9)
			sur = sur.substr(0, 9) + ".";
		str nick = list[i].getNick();
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
		std::cout << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << fore << " | ";
		std::cout << std::setw(10) << sur << " | ";
		std::cout << std::setw(10) << nick << std::endl;
	}
	std::cout << std::endl << "Enter Index to see more: " << std::endl;
	input = get_input();
	while (1)
	{
		if (input.length() == 1)
		{
			int i = input[0] - 48;
			if (i >= 1 && i <= current_size)
			{
#ifdef NICE
				system("clear");
#endif
				std::cout << "Contact " << i << std::endl;
				std::cout << "Forename: " << list[i - 1].getFore() << std::endl;
				std::cout << "Surname: " << list[i - 1].getSur() << std::endl;
				std::cout << "Nickname: " << list[i - 1].getNick() << std::endl;
				std::cout << "Phone: " << list[i - 1].getPhone() << std::endl;
				std::cout << "Secret: " << list[i - 1].getSecret() << std::endl;
				break;
			}
			else
			{
#ifdef NICE
				system("clear");
#endif
				std::cout << "ERROR" << std::endl;
				return;
			}
		}
		else
		{
			std::cout << "ERROR" << std::endl;
			return;
		}
	}
}