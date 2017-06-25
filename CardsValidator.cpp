#include "CardsValidator.hpp"
#include <stdexcept>

CardsValidator::CardsValidator(Card startingCard)
{
    this->startingCard = startingCard;
}

void CardsValidator::checkIfCardsCouldBeThrown(Cards cards, Cards cardsOnTableTop)
{
    if (not cardsOnTableTop.size())
    {
        validateGameStartingCards(cards);
    }
    else
    {
        throw std::runtime_error("Only starting cards available");
    }
}

void CardsValidator::validateGameStartingCards(Cards cards)
{
    bool startingCardFound = false;

    for (unsigned int i = 0; i < cards.size(); i++)
    {
        if (cards[i] == startingCard)
        {
            startingCardFound = true;
            break;
        }

        if (cards[i].value != startingCard.value)
        {
            throw std::runtime_error("You have to start with starting card");
        }
    }

    if (not startingCardFound)
    {
        throw std::runtime_error("You have to start with starting card");
    }
}

