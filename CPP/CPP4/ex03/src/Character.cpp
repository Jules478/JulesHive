#include "../inc/Character.hpp"

Character::Character() : _name("Default Character")
{
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
}

Character::Character(str name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
}

Character::Character(const Character& copy)
{
	_name = copy.getName();
	for (int i = 0; i < 4; i++)
		_inv[i] = copy._inv[i] ? copy._inv[i]->clone() : nullptr;
}

Character& Character::operator=(const Character& copy)
{
	if (this != &copy)
	{
		this->_name = copy.getName();
		for (int i = 0; i < 4; i++)
			_inv[i] = copy._inv[i] ? copy._inv[i]->clone() : nullptr;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inv[i])
			delete _inv[i];
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inv[i])
		{
			_inv[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (_inv[idx])
		_inv[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (_inv[idx])
		_inv[idx]->use(target);
}

const str& Character::getName() const
{
	return _name;
}

AMateria* Character::getMateria(int idx) const
{
	return _inv[idx];
}