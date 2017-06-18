#include "Card.hpp"

Card::Card() {}

Card::Card(Color color, Value value)
{
    this->color = color;
    this->value = value;
    selected = false;
}
