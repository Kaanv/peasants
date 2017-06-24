#include "Table.hpp"

Cards Table::getCardsFromTop()
{
    return cardsOnTop;
}

void Table::throwCards(Cards cards)
{
    cardsOnTop = cards;
    for (int i = 0; i < cardsOnTop.size(); i++)
    {
        cardsOnTop[i].selected = false;
    }
}
