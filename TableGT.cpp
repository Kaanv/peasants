#include "gtest/gtest.h"
#include "Table.hpp"

namespace
{

class TableTest : public ::testing::Test {};

TEST_F(TableTest, EmptyVectorOfCardsShouldBeReturnedWhenNoCardsThrown)
{
    Table table;
    EXPECT_EQ(Cards(), table.getCardsFromTop());
}

TEST_F(TableTest, CardsThatWereThrownShouldBeGettableFromTable)
{
    Table table;
    Cards cards = {Card(seven, hearts), Card(seven, spades)};
    table.throwCards(cards);
    EXPECT_EQ(cards, table.getCardsFromTop());
}

TEST_F(TableTest, OnlyLastCardsThatWereThrownShouldBeOnTop)
{
    Table table;
    Cards cards = {Card(seven, hearts), Card(seven, spades)};
    Cards cardsThrownLater = {Card(eight, hearts), Card(eight, spades)};
    table.throwCards(cards);
    table.throwCards(cardsThrownLater);
    EXPECT_EQ(cardsThrownLater, table.getCardsFromTop());
}

}
