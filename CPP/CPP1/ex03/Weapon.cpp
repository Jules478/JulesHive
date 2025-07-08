#include "Weapon.hpp"

Weapon::Weapon(str type) : _type(type)
{
}

Weapon::~Weapon()
{
}

const str &Weapon::getType() const
{
	return _type;
}

void Weapon::setType(str type)
{
	_type = type;
}