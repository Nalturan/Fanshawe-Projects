#include "StaticLib_Level.h"
#include <iostream>

// Initalization of variables
void cLevel::Init(int sLevel, int sExp)
{
	level = sLevel;
	if (level <= 0)
	{
		level = 1;
	}
	expValue = sExp;
	if (expValue < 0)
	{
		expValue = 0;
	}
}

//ctors
cLevel::cLevel()
{
	Init(1, 0);
}

cLevel::cLevel(int sLevel, int sExp)
{
	Init(sLevel, sExp);
}


// Set max experience value
void cLevel::SetMaxExp()
{
	maxExp = 100 * level;
}


// Getters
int cLevel::GetLevel()
{
	return level;
}

int cLevel::GetExpValue()
{
	return expValue;
}

int cLevel::GetMaxExp()
{
	return maxExp;
}


// Count player experience
void cLevel::ExpGain()
{
	expValue += 10;
	if (expValue > maxExp)
	{
		expValue = maxExp;
	}
}

// Check if max exp has been reached
bool cLevel::MaxExpAchived()
{
	return expValue = maxExp;
}

// Upon reaching max exp:
// Reset exp value
// Up the level of the player
// Up max exp value
void cLevel::LevelUp()
{
	std::cout << "Level UP!\n" << std::endl;
	level += 1;
	expValue = 0;
	SetMaxExp();
}

// Upon reaching Player death:
// Reset exp value
// Lower the level of the player
// Lower max exp value
void cLevel::LevelDown()
{
	std::cout << "Level Down! Be more careful out there.\n" << std::endl;
	level -= 1;
	expValue = 0;
	SetMaxExp();
}
