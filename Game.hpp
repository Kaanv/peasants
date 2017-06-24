#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include "Table.hpp"

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
    Cards getCardsFromTableTop();
    void passCurrentPlayerTurn();
    void checkIfCardsHaveSameValue(Cards cards);
    void checkIfCardsCouldBeThrown(Cards cards);

private:
    Players players;
    Deck deck;
    int currentPlayerId;
    int passedTurns;
    Table table;
};

#endif
