#include <gtest/gtest.h>
#include <DynamicLib_Player.h>
#include <StaticLib_Level.h>
#include <iostream>


// Test fixture for cDynamicLib_Player and cLevel class
struct CombinedTestFixture : testing::Test
{
	cDynamicLib_Player* player;
	cLevel* level;

	CombinedTestFixture()
	{
		std::cout << "Start Test\n" << std::endl;
	}

	virtual ~CombinedTestFixture()
	{
		std::cout << "End test" << std::endl;
	}

	// Called at the beginning of Test
	void SetUp()
	{
		player = new cDynamicLib_Player();
		level = new cLevel();
		level->SetMaxExp();
	}

	// Called at the beginning of Test with input
	void SetUp(int sStrength, int sDexterity, int sIntelligence, int sConstitution, int sCharisma, int sLevel, int sExp)
	{
		player = new cDynamicLib_Player(sStrength, sDexterity, sIntelligence, sConstitution, sCharisma, sLevel);
		level = new cLevel(sLevel, sExp);
		level->SetMaxExp();
	}

	//Function to gain experience for LevelUp()
	void LvlExpFarm()
	{
		int expGain = level->GetExpValue();
		int expMax = level->GetMaxExp();
		expMax = expMax / 10;
		if (expGain != expMax)
		{
			level->ExpGain();
			expGain++;
		}
	}

	// Called at the end of Test
	virtual void TearDown()
	{
		delete player;
		delete level;
	}
};


// Check if player has reached max level
TEST_F(CombinedTestFixture, PlayerLevelUp)
{
	SetUp();
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	level->LevelUp();
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	level->LevelUp();
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	level->LevelUp();
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	level->LevelUp();
	EXPECT_FALSE(player->MaxLvlCheck(level->GetLevel()));
}

// Check if player can level up stats
TEST_F(CombinedTestFixture, PlayerLevelStatUp)
{
	SetUp();
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	level->LevelUp();
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	level->LevelUp();
	player->StatUp(level->GetLevel());
	EXPECT_EQ(player->GetStats(0), 14);
	EXPECT_EQ(player->GetStats(1), 14);
	EXPECT_EQ(player->GetStats(2), 14);
	EXPECT_EQ(player->GetStats(3), 14);
	EXPECT_EQ(player->GetStats(4), 14);
}

// Check if player can level up custom stats
TEST_F(CombinedTestFixture, PlayerLevelCustomStatUp)
{
	SetUp(40, 35, 17, 33, 24, 3, 0);
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	level->LevelUp();
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	level->LevelUp();
	player->StatUp(level->GetLevel());
	EXPECT_EQ(player->GetStats(0), 44);
	EXPECT_EQ(player->GetStats(1), 39);
	EXPECT_EQ(player->GetStats(2), 21);
	EXPECT_EQ(player->GetStats(3), 37);
	EXPECT_EQ(player->GetStats(4), 28);
}

// Check if player can level up beyond limits
TEST_F(CombinedTestFixture, PlayerLevelCap)
{
	SetUp(40, 35, 17, 33, 24, 20, 0);
	LvlExpFarm();
	EXPECT_TRUE(level->MaxExpAchived());
	EXPECT_TRUE(player->MaxLvlCheck(level->GetLevel()));
	//Only if you try to attempt to lvl up after MaxLvlCheck()
	//EXPECT_EQ(level->GetLevel(), 20);
}

// Check if stats reflect players lower level
TEST_F(CombinedTestFixture, StatUpTest)
{
	SetUp(12, 14, 16, 18, 20, 15, 0);
	level->LevelDown();
	player->StatUp(level->GetLevel());
	EXPECT_EQ(player->GetStats(0), 10);
	EXPECT_EQ(player->GetStats(1), 12);
	EXPECT_EQ(player->GetStats(2), 14);
	EXPECT_EQ(player->GetStats(3), 16);
	EXPECT_EQ(player->GetStats(4), 18);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}