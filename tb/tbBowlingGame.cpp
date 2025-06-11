#include "BowlingGame.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

TEST(BowlingGameTest, StrikeBonus) {
    Player player("Test");
    player.roll(10); // Strike
    player.roll(5);
    player.roll(4);
    EXPECT_EQ(player.getScore(), 28);
}

TEST(BowlingGameTest, SpareBonus) {
    Player player("Test");
    player.roll(4);
    player.roll(6); // Spare
    player.roll(5);
    player.roll(3);
    EXPECT_EQ(player.getScore(), 23);
}

TEST(BowlingGameTest, TenthFrameAllStrikes) {
    Player player("Test");
    for (int i = 0; i < 9; ++i) {
        player.roll(0);
        player.roll(0);
    }
    player.roll(10);
    player.roll(10);
    player.roll(10);
    EXPECT_EQ(player.getScore(), 10);
}

TEST(BowlingGameTest, PerfectGame) {
    Player player("Test");
    for (int i = 0; i < 12; ++i)
    {
        player.roll(10);
    }
    cout << "Score: " <<  player.getScore() << endl;
    EXPECT_EQ(player.getScore(), 280);
}

TEST(BowlingGameTest, RollCountNegativeTest) {
    Player player("Test");
    for (int i = 0; i < 10; ++i)
    {
        player.roll(i);
        player.roll(i);
    }
    bool isExceptionRaised = false;

    try
    {
        player.roll(5);
        player.roll(5);
    }
    catch(const std::exception& e)
    {
        isExceptionRaised = true;
    }
    
    ASSERT_TRUE(isExceptionRaised == true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
