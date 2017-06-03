#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Card.hpp"
#include "Deck.hpp"

class Game
{
public:
    Game(int numberOfPlayers) : deck(numberOfPlayers)
    {
        for (int i = 0; i < numberOfPlayers; i++)
        {
            players.push_back(Player(i));
        }

        distributeCardsFromDeck();
        currentPlayerId = findStartingPlayer();
    }

    void distributeCardsFromDeck()
    {

    }

    int findStartingPlayer()
    {
        return 0;
    }

    bool hasEnded()
    {
        return false;
    }

    Player getCurrentPlayer()
    {
        return players[currentPlayerId];
    }

    void nextPlayer()
    {
        currentPlayerId = (currentPlayerId + 1) % players.size();
    }

private:
    Players players;
    Deck deck;
    int currentPlayerId;
};

#endif
