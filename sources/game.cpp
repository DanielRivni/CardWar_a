#include <string>
#include "game.hpp"
using namespace ariel;

Game::Game(Player p1, Player p2)
{
    this->p1 = new Player(p1);
    this->p2 = new Player(p2);
}
Game::~Game() {}

void Game::playTurn() {}
void Game::printLastTurn() {}
void Game::playAll() {}
void Game::printWiner() {}
void Game::printLog() {}
void Game::printStats() {}