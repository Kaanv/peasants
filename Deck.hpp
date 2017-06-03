#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"

class Deck
{
public:
    Deck(int numberOfPlayers)
    {
        for (int i = 0; i < 4; i++)
        {

        }
    }
    void shuffleCards();
    Card takeCard();

private:
    Cards cards;
};
#endif
