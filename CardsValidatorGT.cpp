#include "gtest/gtest.h"
#include "CardsValidator.hpp"

namespace
{

class CardsValidatorTest : public ::testing::Test {
protected:
    CardsValidatorTest() : sut(Card(seven, hearts)) {}
    virtual ~CardsValidatorTest() {}

    CardsValidator sut;
};

TEST_F(CardsValidatorTest, WhenThereIsNoCardsOnTableAndCardDifferentThanSevenHertsIsThrownThenErrorShouldBeRaised)
{
    EXPECT_THROW(sut.checkIfCardsCouldBeThrown(Cards({Card(eight, hearts)}), Cards({})), std::runtime_error);
}

TEST_F(CardsValidatorTest, WhenThereIsNoCardsOnTableSevenHeartsMayBeThrown)
{
    EXPECT_NO_THROW(sut.checkIfCardsCouldBeThrown(Cards({Card(seven, hearts)}), Cards({})));
}

TEST_F(CardsValidatorTest, WhenThereIsNoCardsOnTableTwoSevensWithSevenHeartsIncludedMayBeThrown)
{
    EXPECT_NO_THROW(sut.checkIfCardsCouldBeThrown(Cards({Card(seven, spades), Card(seven, hearts)}), Cards({})));
}

TEST_F(CardsValidatorTest, WhenThereIsCardDifferentThanSevenErrorShouldBeRaised)
{
    EXPECT_THROW(sut.checkIfCardsCouldBeThrown(Cards({Card(eight, hearts), Card(seven, hearts)}), Cards({})), std::runtime_error);
}

}
