#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;
namespace ariel
{
    class Player
    {
    private:
        string name;
        int stackSize;
        int pile;

    public:
        Player(string name);
        Player(Player &p);
        ~Player();
        string getName();
        int stacksize();
        void setStackSize(int size);

        int cardesTaken();
        void setCardesTaken(int size);
    };
}

#endif