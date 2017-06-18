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

void Player::selectCards(std::vector<int> cardIds)
{
    for (unsigned int i = 0; i < cardIds.size(); i++)
    {
        selectCard(cardIds[i]);
    }
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

void Player::useSelectedCards()
{

}

int Player::getId()
{
    return playerId;
}

