#include "Phonebook.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFore(str fore)
{
	this->forename = fore;
}

void Contact::setSur(str sur)
{
	this->surname = sur;
}

void Contact::setNick(str nick)
{
	this->nickname = nick;
}

void Contact::setPhone(str phone)
{
	this->phone = phone;
}

void Contact::setSecret(str secret)
{
	this->secret = secret;
}

str Contact::getFore() const
{
	return this->forename;
}

str Contact::getSur() const
{
	return this->surname;
}

str Contact::getNick() const
{
	return this->nickname;
}

str Contact::getPhone() const
{
	return this->phone;
}

str Contact::getSecret() const
{
	return this->secret;
}
