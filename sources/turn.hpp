#ifndef TURN_H
#define TURN_H

#include "card.hpp"
#include "player.hpp"
using namespace std;
namespace ariel
{
    class Turn
    {
    private:
        Card *p1Card;
        Card *p2Card;

    public:
        Turn(Card c1, Card c2);
        ~Turn();
        Card *getWinner();
    };

};

#endif