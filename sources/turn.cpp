#include "turn.hpp"

using namespace ariel;

Turn::Turn(Card c1, Card c2)
{
    this->p1Card = new Card(c1);
    this->p2Card = new Card(c2);
}
Turn::~Turn() {}

Card *Turn::getWinner()
{
    if (this->p1Card->getNum() == this->p2Card->getNum())
        return nullptr;

    if (this->p1Card->getNum() > this->p2Card->getNum())
        return this->p1Card;

    return this->p2Card;
}