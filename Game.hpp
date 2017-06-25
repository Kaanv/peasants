#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Card.hpp"
#include "Deck.hpp"
#include "Table.hpp"
#include "CardsValidator.hpp"

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

private:
    Players players;
    Deck deck;
    CardsValidator cardsValidator;
    int currentPlayerId;
    unsigned int passedTurns;
    Table table;
};

#endif
