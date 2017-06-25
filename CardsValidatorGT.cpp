#include "gtest/gtest.h"
#include "CardsValidator.hpp"

namespace
{

class CardsValidatorTest : public ::testing::Test {
protected:
    CardsValidatorTest() {}
    virtual ~CardsValidatorTest() {}

    CardsValidator sut;
};

TEST_F(CardsValidatorTest, WhenThereIsNoCardsOnTableAndCardDifferentThanSevenHertsIsThrownThenErrorShouldBeRaised)
{
    EXPECT_THROW(sut.checkIfCardsCouldBeThrown(Cards({Card(eight, hearts)}), Cards({})), std::runtime_error);
}

}
