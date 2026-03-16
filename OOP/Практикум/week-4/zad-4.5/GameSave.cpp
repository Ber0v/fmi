#include "GameSave.h"
#include <iostream>
#include <fstream>

using namespace std;

struct FileHeader
{
	unsigned nameLength;
	unsigned health;
	int heroClass;
	unsigned damage;
	double attackSpeed;
	unsigned achievementCount;
};

void freeGameSave(GameSave& save)
{
	delete[] save.achievements;
	save.achievements = nullptr;
	save.achievementCount = 0;
	save.hero.name.clear();
	save.hero.health = 0;
	save.hero.heroClass = CharacterClass::Mage;
	save.hero.weapon.damage = 0;
	save.hero.weapon.attackSpeed = 0.0;
}

const char* classToString(CharacterClass heroClass)
{
	switch (heroClass)
	{
	case CharacterClass::Mage: return "Mage";
	case CharacterClass::Warrior: return "Warrior";
	case CharacterClass::Healer: return "Healer";
	case CharacterClass::Rogue: return "Rogue";
	default: return "Unknown";
	}
}

void printCharacter(const Character& hero)
{
	cout << "Hero:\n";
	cout << "Name: " << hero.name << '\n';
	cout << "Health: " << hero.health << '\n';
	cout << "Class: " << classToString(hero.heroClass) << '\n';
	cout << "Weapon damage: " << hero.weapon.damage << '\n';
	cout << "Weapon attack speed: " << hero.weapon.attackSpeed << '\n';
}

void printAchievements(const bool* achievements, unsigned count)
{
	if (achievements == nullptr && count > 0)
	{
		cout << "Achievements array is null\n";
		return;
	}

	cout << "Achievements:\n";
	for (unsigned i = 0; i < count; i++)
	{
		cout << i + 1 << ". " << (achievements[i] ? "Unlocked" : "Locked") << '\n';
	}
}

void printGameSave(const GameSave& save)
{
	printCharacter(save.hero);
	printAchievements(save.achievements, save.achievementCount);
}

bool saveGame(const char* fileName, const GameSave& save)
{
	if (fileName == nullptr)
	{
		cout << "Invalid file name\n";
		return false;
	}

	if (save.hero.health > 100)
	{
		cout << "Invalid hero health\n";
		return false;
	}

	if (save.hero.weapon.damage > 10)
	{
		cout << "Invalid weapon damage\n";
		return false;
	}

	if (save.achievementCount > 0 && save.achievements == nullptr)
	{
		cout << "Achievements array is null\n";
		return false;
	}

	ofstream file(fileName, ios::binary);
	if (!file.is_open())
	{
		cout << "Could not open file for writing\n";
		return false;
	}

	FileHeader header;
	header.nameLength = save.hero.name.size();
	header.health = save.hero.health;
	header.heroClass = (int)save.hero.heroClass;
	header.damage = save.hero.weapon.damage;
	header.attackSpeed = save.hero.weapon.attackSpeed;
	header.achievementCount = save.achievementCount;

	file.write((const char*)&header, sizeof(header));
	if (!file)
	{
		cout << "Error while writing header\n";
		file.close();
		return false;
	}

	file.write(save.hero.name.c_str(), header.nameLength);
	if (!file)
	{
		cout << "Error while writing hero name\n";
		file.close();
		return false;
	}

	for (unsigned i = 0; i < save.achievementCount; i++)
	{
		unsigned char value = save.achievements[i] ? 1 : 0;
		file.write((const char*)&value, sizeof(value));

		if (!file)
		{
			cout << "Error while writing achievements\n";
			file.close();
			return false;
		}
	}

	file.close();

	if (!file)
	{
		cout << "Error while closing file after write\n";
		return false;
	}

	return true;
}

bool loadGame(const char* fileName, GameSave& save)
{
	if (fileName == nullptr)
	{
		cout << "Invalid file name\n";
		return false;
	}

	ifstream file(fileName, ios::binary);
	if (!file.is_open())
	{
		cout << "Could not open file for reading\n";
		return false;
	}

	freeGameSave(save);

	FileHeader header;
	file.read((char*)&header, sizeof(header));
	if (!file)
	{
		cout << "Error while reading header\n";
		file.close();
		return false;
	}

	if (header.health > 100)
	{
		cout << "Invalid health in file\n";
		file.close();
		return false;
	}

	if (header.damage > 10)
	{
		cout << "Invalid damage in file\n";
		file.close();
		return false;
	}

	char* buffer = new (nothrow) char[header.nameLength + 1];
	if (buffer == nullptr)
	{
		cout << "Memory allocation error for name buffer\n";
		file.close();
		return false;
	}

	file.read(buffer, header.nameLength);
	if (!file)
	{
		cout << "Error while reading hero name\n";
		delete[] buffer;
		file.close();
		return false;
	}

	buffer[header.nameLength] = '\0';
	save.hero.name = buffer;
	delete[] buffer;

	save.hero.health = header.health;
	save.hero.heroClass = (CharacterClass)header.heroClass;
	save.hero.weapon.damage = header.damage;
	save.hero.weapon.attackSpeed = header.attackSpeed;
	save.achievementCount = header.achievementCount;

	if (save.achievementCount == 0)
	{
		save.achievements = nullptr;
		file.close();
		return true;
	}

	save.achievements = new (nothrow) bool[save.achievementCount];
	if (save.achievements == nullptr)
	{
		cout << "Memory allocation error for achievements\n";
		file.close();
		return false;
	}

	for (unsigned i = 0; i < save.achievementCount; i++)
	{
		unsigned char value = 0;
		file.read((char*)&value, sizeof(value));

		if (!file)
		{
			cout << "Error while reading achievements\n";
			freeGameSave(save);
			file.close();
			return false;
		}

		save.achievements[i] = (value == 1);
	}

	file.close();

	if (!file && !file.eof())
	{
		cout << "Error while closing file after read\n";
		return false;
	}

	return true;
}

bool checkAchievement(const char* fileName, unsigned index)
{
	if (fileName == nullptr)
	{
		cout << "Invalid file name\n";
		return false;
	}

	ifstream file(fileName, ios::binary);
	if (!file.is_open())
	{
		cout << "Could not open file for reading\n";
		return false;
	}

	FileHeader header;
	file.read((char*)&header, sizeof(header));
	if (!file)
	{
		cout << "Error while reading header\n";
		file.close();
		return false;
	}

	if (index >= header.achievementCount)
	{
		cout << "Invalid achievement index\n";
		file.close();
		return false;
	}

	streampos pos = sizeof(FileHeader) + header.nameLength + index * sizeof(unsigned char);
	file.seekg(pos, ios::beg);
	if (!file)
	{
		cout << "Seek error\n";
		file.close();
		return false;
	}

	unsigned char value = 0;
	file.read((char*)&value, sizeof(value));
	if (!file)
	{
		cout << "Error while reading achievement value\n";
		file.close();
		return false;
	}

	file.close();
	return value == 1;
}