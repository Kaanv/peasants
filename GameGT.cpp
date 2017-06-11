#include "gtest/gtest.h"
#include "Game.hpp"

namespace
{

class GameTest : public ::testing::Test {
protected:
    GameTest()
    {
    }

    virtual ~GameTest()
    {

    }
};

TEST_F(GameTest, MethodBarDoesAbc)
{
    EXPECT_EQ(0, 0);
}

}
