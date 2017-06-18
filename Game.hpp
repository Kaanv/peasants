#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Card.hpp"
#include "Deck.hpp"

class Table
{

};

class Game
{
public:
    Game(int numberOfPlayers);

    void distributeCardsFromDeck();
    int findStartingPlayer();
    bool hasEnded();
    Player &getCurrentPlayer();
    void nextPlayer();
    void throwCards(Cards cards);

private:
    Players players;
    Deck deck;
    int currentPlayerId;
    Table table;
};

#endif
