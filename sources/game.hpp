#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "turn.hpp"

#include <vector>

namespace ariel
{
    class Game
    {
    private:
        Player *p1;
        Player *p2;

    public:
        std::vector<Turn> turns;

        Game(Player p1, Player p2);
        ~Game();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}

#endif