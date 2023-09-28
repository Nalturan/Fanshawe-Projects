#include "DynamicLib_Player.h"
#include <iostream>

// Initialization of stat variables
void cDynamicLib_Player::Init(int sStrength, int sDexterity, int sIntelligence, int sConstitution, int sCharisma, int sLevel)
{
	strength = sStrength;
	if (strength <= 0)
	{
		strength = 10;
	}
	dexterity = sDexterity;
	if (dexterity <= 0)
	{
		dexterity = 10;
	}
	intelligence = sIntelligence;
	if (intelligence <= 0)
	{
		intelligence = 10;
	}
	constitution = sConstitution;
	if (constitution <= 0)
	{
		constitution = 10;
	}
	charisma = sCharisma;
	if (charisma <= 0)
	{
		charisma = 10;
	}
	level = sLevel;
	if (level <= 0)
	{
		level = 1;
	}
	statLvlCheck = level;
	maxLvl = 20;
	maxStats = 50;
}

//ctors
cDynamicLib_Player::cDynamicLib_Player()
{
	Init(10, 10, 10, 10, 10, 1);
}

cDynamicLib_Player::cDynamicLib_Player(int sStrength, int sDexterity, int sIntelligence, int sConstitution, int sCharisma, int sLevel)
{
	Init(sStrength, sDexterity, sIntelligence, sConstitution, sCharisma, sLevel);
}

//Get player stats
int cDynamicLib_Player::GetStats(int aStat)
{
	//variable to call stats in array
	int pStat = aStat;
	if (pStat < 0)
	{
		pStat = 0;
	}
	static int stats[5];
	stats[0] = strength;
	stats[1] = dexterity;
	stats[2] = intelligence;
	stats[3] = constitution;
	stats[4] = charisma;

	return stats[pStat];

}


// Check if maxLvl has been exceeded
bool cDynamicLib_Player::MaxLvlCheck(int pLevel)
{
	level = pLevel;
	if (level == maxLvl)
	{
		std::cout << "Player Level has reached the limits!!! Further growth is Impossible\n" << std::endl;
		return true;
	}
	return false;
}

// Check if maxStats have been exceeded
bool cDynamicLib_Player::MaxStatsCheck()
{
	// Check Strength
	if (strength > maxStats)
	{
		std::cout << "Player Strength has exceeded the limits applied!!!\n" << std::endl;
		return true;
	}
	// Check Dexterity
	if (dexterity > maxStats)
	{
		std::cout << "Player Dexterity has exceeded the limits applied!!!\n" << std::endl;
		return true;
	}
	// Check Intelligence
	if (intelligence > maxStats)
	{
		std::cout << "Player Intelligence has exceeded the limits applied!!!\n" << std::endl;
		return true;
	}
	// Check Constitution
	if (constitution > maxStats)
	{
		std::cout << "Player Constitution has exceeded the limits applied!!!\n" << std::endl;
		return true;
	}
	// Check Charisma
	if (charisma > maxStats)
	{
		std::cout << "Player Charisma has exceeded the limits applied!!!\n" << std::endl;
		return true;
	}
	// All stats are within limits
    return false;
}

//Up all stats for player level up
void cDynamicLib_Player::StatUp(int pLevel)
{
	level = pLevel;
	if (level == statLvlCheck)
	{
		std::cout << "Player has acheived max stats for this level. Please farm more exp and level up again before attempting to alter stats further.\n" << std::endl;
	}
	for (;level > statLvlCheck;	statLvlCheck += 1)
	{
		strength += 2;
		dexterity += 2;
		intelligence += 2;
		constitution += 2;
		charisma += 2;
	}
	for (;level < statLvlCheck; statLvlCheck -= 1)
	{
		strength -= 2;
		dexterity -= 2;
		intelligence -= 2;
		constitution -= 2;
		charisma -= 2;
	}


}
