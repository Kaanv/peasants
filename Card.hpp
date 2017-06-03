#ifndef CARD_HPP
#define CARD_HPP

#include <vector>

enum Color
{
    heart,
    diamond,
    club,
    spades
};

enum Value
{
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace
};

struct Card
{
    Color color;
    Value value;
};

typedef std::vector<Card> Cards;

#endif
