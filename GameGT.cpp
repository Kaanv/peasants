#include "gtest/gtest.h"
#include "Game.hpp"

namespace
{

class GameTest : public ::testing::Test {
protected:
    GameTest() : game(4) {}

    virtual ~GameTest() {}

    Game game;

    void assertThatStartingPlayerHasStartingCard()
    {
        bool startingCardFound = false;
        Cards playerCards = game.getCurrentPlayer().getCards();

        for (unsigned int j = 0; j < playerCards.size(); j++)
        {
            if (playerCards[j] == Card(seven, hearts))
            {
                startingCardFound = true;
            }
        }

        ASSERT_TRUE(startingCardFound);
    }
};

TEST_F(GameTest, StartingPlayerShouldHaveStartingCard)
{
    assertThatStartingPlayerHasStartingCard();
}

}
