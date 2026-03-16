#pragma once

#include "Character.h"
#include <string>

struct GameSave
{
	Character hero;
	unsigned achievementCount;
	bool* achievements;
};

void freeGameSave(GameSave& save);

const char* classToString(CharacterClass heroClass);

void printCharacter(const Character& hero);
void printAchievements(const bool* achievements, unsigned count);
void printGameSave(const GameSave& save);

bool saveGame(const char* fileName, const GameSave& save);
bool loadGame(const char* fileName, GameSave& save);
bool checkAchievement(const char* fileName, unsigned index);