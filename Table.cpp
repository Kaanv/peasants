#include "Table.hpp"

Cards Table::getCardsFromTop()
{
    return cardsOnTop;
}

void Table::throwCards(Cards cards)
{
    cardsOnTop = cards;
}
