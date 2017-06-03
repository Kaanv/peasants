#include "Player.hpp"

Player::Player(int playerId)
{
    this->playerId = playerId;
}

Cards Player::getCards()
{
    return cards;
}

int Player::getId()
{
    return playerId;
}

