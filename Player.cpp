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

int Player::getId()
{
    return playerId;
}

