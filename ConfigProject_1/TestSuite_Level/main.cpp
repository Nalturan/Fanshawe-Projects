#include <gtest/gtest.h>
#include <StaticLib_Level.h>
#include <iostream>


// Test fixture for cLevel class
struct sLevelTestFixture : testing::Test 
{
	cLevel* player;

	sLevelTestFixture()
	{
		std::cout << "Start Test\n" << std::endl;
	}

	virtual ~sLevelTestFixture()
	{
		std::cout << "End test" << std::endl;
	}

	// Called at the beginning of Test
	void SetUp()
	{
		player = new cLevel();
		player->SetMaxExp();
	}

	// Called at the beginning of Test with input
	void SetUp(int sLevelStart, int sExpStart)
	{
		player = new cLevel(sLevelStart, sExpStart);
		player->SetMaxExp();
	}

	//Function to gain experience for LevelUp()
	void LvlExpFarm()
	{
		int expGain = player->GetExpValue();
		int expMax = player->GetMaxExp();
		expMax = expMax / 10;
		if (expGain != expMax)
		{
			player->ExpGain();
			expGain++;
		}
	}

	// Called at the end of Test
	virtual void TearDown()
	{
		delete player;
	}
};


// Check if player default level is 1 and player exp default is 0
TEST_F(sLevelTestFixture, DefaultValue)
{
	SetUp();
	EXPECT_EQ(player->GetLevel(), 1);
	EXPECT_EQ(player->GetExpValue(), 0);
}

// Check if player exp increase is 10
TEST_F(sLevelTestFixture, Experience)
{
	SetUp();
	player->ExpGain();
	EXPECT_EQ(player->GetExpValue(), 10);
}

// Test LevelUp() is functioning correctly
TEST_F(sLevelTestFixture, LvlUp)
{
	SetUp();
	// Set exp to max
	LvlExpFarm();
	// Check to make sure Player is max exp
	EXPECT_TRUE(player->MaxExpAchived());
	player->LevelUp();
	EXPECT_EQ(player->GetLevel(), 2);
	EXPECT_EQ(player->GetExpValue(), 0);
	EXPECT_EQ(player->GetMaxExp(), 200);
}

// Test that player level and exp cannot be negetive
TEST_F(sLevelTestFixture, CustomValue)
{
	SetUp(-1, -35);
	EXPECT_EQ(player->GetLevel(), 1);
	EXPECT_EQ(player->GetExpValue(), 0);
}

//Test for input not being an integer, level and exp should default correctly
TEST_F(sLevelTestFixture, NullValues)
{
	SetUp(NULL, 0.34f);
	EXPECT_EQ(player->GetLevel(), 1);
	EXPECT_EQ(player->GetExpValue(), 0);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}