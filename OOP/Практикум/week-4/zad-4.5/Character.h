#pragma once

#include "Weapon.h"
#include <string>

enum class CharacterClass
{
	Mage,
	Warrior,
	Healer,
	Rogue
};

struct Character
{
	std::string name;
	unsigned health;
	CharacterClass heroClass;
	Weapon weapon;
};