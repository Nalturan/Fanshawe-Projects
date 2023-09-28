#pragma once
#include <string>
#define DLLExport __declspec (dllexport)

// Class that deals with player information
class DLLExport cDynamicLib_Player
{
private:
	// Player stats
	int strength;
	int dexterity;
	int intelligence;
	int constitution;
	int charisma;
	// Maximun values for level and stats
	int level;
	int statLvlCheck;
	int maxLvl;
	int maxStats;

	// Initialization of internal values
	void Init(int sStrength, int sDexterity, int sIntelligence, int sConstitution, int sCharisma, int sLevel);

public:
	std::string player;

	//ctors
	cDynamicLib_Player();
	cDynamicLib_Player(int sStrength, int sDexterity, int sIntelligence, int sConstitution, int sCharisma, int sLevel);

	// Getters
	int GetStats(int aStat);

	// Player stat/level handling classes
	bool MaxLvlCheck(int pLevel);
	bool MaxStatsCheck();
	void StatUp(int pLevel);

};

