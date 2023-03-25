#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
namespace ariel
{
    class Card
    {
    private:
        int num;
        string shape;

    public:
        Card(int num, string shape);
        Card(Card &card);
        ~Card();
        int getNum();
        string getShape();
    };
}

#endif