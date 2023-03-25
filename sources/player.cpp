#include "player.hpp"
using namespace ariel;

Player::Player(string name) {}
Player::Player(Player &p) {}
Player::~Player() {}

string Player::getName() { return name; }
int Player::stacksize() { return 0; }
int Player::cardesTaken() { return 0; }
void Player::setStackSize(int size)
{
    this->stackSize = size;
}
void Player::setCardesTaken(int size)
{
    this->pile = size;
}
