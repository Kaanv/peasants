#include "Player.hpp"
#include <iostream>

Player::Player(int playerId)
{
    this->playerId = playerId;
}

Cards Player::getCards()
{
    return cards;
}

void Player::insertCard(Card card)
{
    cards.push_back(card);
}

void Player::selectCard(int cardId)
{
    cards[cardId].select();
}

void Player::unselectCard(int cardId)
{
    cards[cardId].selected = false;
}

void Player::unselectCards(std::vector<int> cardIds)
{
    for (unsigned int i = 0; i < cardIds.size(); i++)
    {
        unselectCard(cardIds[i]);
    }
}

void Player::unselectAllCards()
{
    for (unsigned int i = 0; i < cards.size(); i++)
    {
        unselectCard(i);
    }
}

Cards Player::getSelectedCards()
{
    Cards selectedCards;

    for (unsigned int i = 0; i < cards.size(); i++)
    {
        if (cards[i].selected)
        {
            selectedCards.push_back(cards[i]);
        }
    }

    return selectedCards;
}

void Player::removeSelectedCards()
{
    for (int i = cards.size() - 1; i >= 0; i--)
    {
        if (cards[i].selected)
        {
            cards.erase(cards.begin() + i);
        }
    }
}

int Player::getId()
{
    return playerId;
}

