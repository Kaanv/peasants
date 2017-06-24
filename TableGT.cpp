#include "gtest/gtest.h"
#include "Table.hpp"

namespace
{

class TableTest : public ::testing::Test {
protected:
    TableTest()
    {
    }

    virtual ~TableTest()
    {

    }
};

TEST_F(TableTest, aaa)
{
    EXPECT_EQ(1, 1);
}

}
