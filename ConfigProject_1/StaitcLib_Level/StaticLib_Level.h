#pragma once

// The cLevel class deals with player levels
class cLevel
{
private:
	int level;
	int expValue;
	int maxExp;

	// Initialization of the inernal values
	void Init(int sLevel, int sExp);

public:

	//ctors
	cLevel();
	cLevel(int sLevel, int sExp);

	// Setters
	void SetMaxExp();

	// Getters
	int GetLevel();
	int GetExpValue();
	int GetMaxExp();

	// Level up classes
	void ExpGain();
	bool MaxExpAchived();
	void LevelUp();
	void LevelDown();

};