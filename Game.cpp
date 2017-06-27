#include "Game.hpp"
#include <stdexcept>

Game::Game(int numberOfPlayers) : deck(numberOfPlayers),
                                  cardsValidator(deck.getStartingCard())
{
    for (int i = 0; i < numberOfPlayers; i++)
    {
        players.push_back(Player(i));
    }

    distributeCardsFromDeck();
    currentPlayerId = findStartingPlayer();
    passedTurns = 0;
}

void Game::distributeCardsFromDeck()
{
    for (unsigned int i = 0; i < players.size(); i++)
    {
        for (int j = 0; j < 8; j++)
        {
            players[i].insertCard(deck.takeCard());
        }
    }
}

int Game::findStartingPlayer()
{
    Card startingCard = deck.getStartingCard();

    for (unsigned int i = 0; i < players.size(); i++)
    {
        Cards playerCards = players[i].getCards();

        for (unsigned int j = 0; j < playerCards.size(); j++)
        {
            if (playerCards[j] == startingCard)
            {
                return i;
            }
        }
    }

    return 0;
}

bool Game::hasEnded()
{
    unsigned int playersThatEnded = 0;

    for (unsigned int i = 0 ; i < players.size(); i++)
    {
        if (players[i].hasEnded())
        {
            playersThatEnded++;
        }
    }

    return playersThatEnded >= players.size() - 1;
}

Player& Game::getCurrentPlayer()
{
    return players[currentPlayerId];
}

void Game::nextPlayer()
{
    currentPlayerId = (currentPlayerId + 1) % players.size();

    if (players[currentPlayerId].hasEnded())
    {
        nextPlayer();
    }
}

void Game::throwCards(Cards cards)
{
    if (passedTurns >= players.size() - 1)
    {
        cardsValidator.checkIfCardsHaveSameValue(cards);
    }
    else
    {
        cardsValidator.checkIfCardsCouldBeThrown(cards, table.getCardsFromTop());
    }

    table.throwCards(cards);
    passedTurns = 0;
}

Cards Game::getCardsFromTableTop()
{
    return table.getCardsFromTop();
}

void Game::passCurrentPlayerTurn()
{
    if (not getCardsFromTableTop().size())
    {
        passedTurns++;
    }
    else
    {
        throw std::runtime_error("Cannot pass starting turn");
    }
}

