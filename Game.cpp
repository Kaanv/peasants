#include "Game.hpp"

Game::Game(int numberOfPlayers) : deck(numberOfPlayers)
{
    for (int i = 0; i < numberOfPlayers; i++)
    {
        players.push_back(Player(i));
    }

    distributeCardsFromDeck();
    currentPlayerId = findStartingPlayer();
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
    return false;
}

Player& Game::getCurrentPlayer()
{
    return players[currentPlayerId];
}

void Game::nextPlayer()
{
    currentPlayerId = (currentPlayerId + 1) % players.size();
}

void Game::throwCards(Cards cards)
{

}

Cards Game::getCardsFromTableTop()
{

}
