#ifndef CARD_HPP
#define CARD_HPP

#include <vector>

enum Color
{
    hearts,
    diamonds,
    clubs,
    spades
};

enum Value
{
    three = 3,
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
    Card();

    Card(Color color, Value value);

    friend bool operator<(const Card& l, const Card& r)
    {
        if (l.value == r.value)
        {
            return l.color < r.color;
        }

        return l.value < r.value;
    }

    Color color;
    Value value;
    bool selected = false;
};

typedef std::vector<Card> Cards;

#endif
