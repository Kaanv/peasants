#include "CardsValidator.hpp"
#include <stdexcept>

void CardsValidator::checkIfCardsCouldBeThrown(Cards cards, Cards cardsOnTableTop)
{
    if (not cardsOnTableTop.size())
    {
        throw std::runtime_error("Wrong card");
    }
}

