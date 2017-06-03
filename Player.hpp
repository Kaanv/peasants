#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Card.hpp"

class Player
{
public:
    Player(int playerId);
    Cards getCards();
    void insertCard(Card card);
    void selectCard(int cardId);
    void selectCards(std::vector<int> cardIds);
    void unselectCard(int cardId);
    void unselectCards(std::vector<int> cardIds);
    void unselectAllCards();
    void useSelectedCards();
    int getId();

private:
    int peasantLevel;
    int playerId;
    Cards cards;
};

typedef std::vector<Player> Players;

#endif
