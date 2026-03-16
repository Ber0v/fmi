#include <iostream>
#include "GameSave.h"

using namespace std;

int main()
{
	GameSave save{};
	save.achievements = nullptr;
	save.achievementCount = 0;

	save.hero.name = "Aldor";
	save.hero.health = 87;
	save.hero.heroClass = CharacterClass::Mage;
	save.hero.weapon.damage = 9;
	save.hero.weapon.attackSpeed = 1.75;

	save.achievementCount = 6;
	save.achievements = new (nothrow) bool[save.achievementCount];
	if (save.achievements == nullptr)
	{
		cout << "Memory allocation error for achievements\n";
		return -1;
	}

	for (unsigned i = 0; i < save.achievementCount; i++)
	{
		save.achievements[i] = false;
	}

	save.achievements[3] = true;
	save.achievements[0] = true;
	save.achievements[5] = true;

	cout << "Original save:\n";
	printGameSave(save);
	cout << '\n';

	if (!saveGame("savegame.dat", save))
	{
		cout << "Save failed\n";
		freeGameSave(save);
		return -1;
	}

	cout << "Game saved successfully\n\n";

	cout << "Achievement 1: " << (checkAchievement("savegame.dat", 0) ? "Unlocked" : "Locked") << '\n';
	cout << "Achievement 2: " << (checkAchievement("savegame.dat", 1) ? "Unlocked" : "Locked") << '\n';
	cout << "Achievement 4: " << (checkAchievement("savegame.dat", 3) ? "Unlocked" : "Locked") << '\n';
	cout << '\n';

	GameSave loaded{};
	loaded.achievements = nullptr;
	loaded.achievementCount = 0;

	if (!loadGame("savegame.dat", loaded))
	{
		cout << "Load failed\n";
		freeGameSave(save);
		return -1;
	}

	cout << "Loaded save:\n";
	printGameSave(loaded);

	freeGameSave(save);
	freeGameSave(loaded);

	return 0;
}