#include "Player.hpp"

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

}

void Player::selectCards(std::vector<int> cardIds)
{

}

void Player::unselectCard(int cardId)
{

}

void Player::unselectCards(std::vector<int> cardIds)
{

}

void Player::unselectAllCards()
{

}

void Player::useSelectedCards()
{

}

int Player::getId()
{
    return playerId;
}

