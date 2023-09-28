#include <gtest/gtest.h>
#include <DynamicLib_Player.h>
#include <iostream>


// Test fixture for cDynamicLib_Player class
struct cDynamicLib_PlayerTestFixture : testing::Test
{
	cDynamicLib_Player* player;

	cDynamicLib_PlayerTestFixture()
	{
		std::cout << "Start Test\n" << std::endl;
	}

	virtual ~cDynamicLib_PlayerTestFixture()
	{
		std::cout << "End test" << std::endl;
	}

	// Called at the beginning of Test
	void SetUp()
	{
		player = new cDynamicLib_Player();
	}

	// Called at the beginning of Test with input
	void SetUp(int sStrength, int sDexterity, int sIntelligence, int sConstitution, int sCharisma, int sLevel)
	{
		player = new cDynamicLib_Player(sStrength, sDexterity, sIntelligence, sConstitution, sCharisma, sLevel);
	}

	// Called at the end of Test
	virtual void TearDown()
	{
		delete player;
	}
};


// Check if default stat values are 10
TEST_F(cDynamicLib_PlayerTestFixture, DefaultStatValue)
{
	SetUp();
	EXPECT_EQ(player->GetStats(0), 10);
	EXPECT_EQ(player->GetStats(1), 10);
	EXPECT_EQ(player->GetStats(2), 10);
	EXPECT_EQ(player->GetStats(3), 10);
	EXPECT_EQ(player->GetStats(4), 10);
}

// Test to see if individual stats are being input correctly
TEST_F(cDynamicLib_PlayerTestFixture, UniqueStatValues)
{
	SetUp(15, 20, 40, 30, 10, 1);
	EXPECT_EQ(player->GetStats(0), 15);
	EXPECT_EQ(player->GetStats(1), 20);
	EXPECT_EQ(player->GetStats(2), 40);
	EXPECT_EQ(player->GetStats(3), 30);
	EXPECT_EQ(player->GetStats(4), 10);
}

// Test to see if stats default to 10 if thrown negatives
TEST_F(cDynamicLib_PlayerTestFixture, NegativeStatValues)
{
	SetUp(-5, -21, -50, -18, -34, 1);
	EXPECT_EQ(player->GetStats(0), 10);
	EXPECT_EQ(player->GetStats(1), 10);
	EXPECT_EQ(player->GetStats(2), 10);
	EXPECT_EQ(player->GetStats(3), 10);
	EXPECT_EQ(player->GetStats(4), 10);
}

// Test to see if stats over the limit are caught
TEST_F(cDynamicLib_PlayerTestFixture, MaxStatCheck)
{
	SetUp(50, 45, 50, 38, 54, 1);
	EXPECT_TRUE(player->MaxStatsCheck());
}

// Test to see if StatUp() properly increases stat value
TEST_F(cDynamicLib_PlayerTestFixture, StatUpTest)
{
	SetUp(12, 14, 16, 18, 20, 1);
	player->StatUp(2);
	EXPECT_EQ(player->GetStats(0), 14);
	EXPECT_EQ(player->GetStats(1), 16);
	EXPECT_EQ(player->GetStats(2), 18);
	EXPECT_EQ(player->GetStats(3), 20);
	EXPECT_EQ(player->GetStats(4), 22);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}