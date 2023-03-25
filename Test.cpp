#include "doctest.h"
#include <stdexcept>
using namespace doctest;
#include <iostream>
#include <sstream>

#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"
using namespace ariel;

TEST_CASE("Start")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    // verify both players have the right amount of cards on game start
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    // verify that both players did not flash a card on game start
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    // verify both players have the right names
    CHECK(p1.getName() == "Alice");
    CHECK(p2.getName() == "Bob");
}
TEST_CASE("Play Turn")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();

    // verify both players have at least one less card in their stacks
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
}
TEST_CASE("Print Turn - Alice Win")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.

    Card c1(12, "Hearts");
    Card c2(5, "Spades");
    game.turns.push_back(Turn(c1, c2));

    std::ostringstream oss;
    std::streambuf *original = std::cout.rdbuf(oss.rdbuf());
    game.printLastTurn();
    std::string lastTurn = oss.str();

    // verify that the printLastTurn is presenting correct
    CHECK(lastTurn == "Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.");
    std::cout.rdbuf(original);
}
TEST_CASE("Print Turn - Draw")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    Card c1(6, "Hearts");
    Card c2(6, "Spades");
    game.turns.push_back(Turn(c1, c2));
    Card c3(10, "Clubs");
    Card c4(10, "Diamonds");
    game.turns.push_back(Turn(c3, c4));
    Card c5(11, "Clubs");
    Card c6(13, "Diamonds");
    game.turns.push_back(Turn(c5, c6));

    std::ostringstream oss;
    std::streambuf *original = std::cout.rdbuf(oss.rdbuf());
    game.printLastTurn();
    std::string lastTurn = oss.str();

    // verify that the printLastTurn is presenting correct
    CHECK(lastTurn == "Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.");
    std::cout.rdbuf(original);
}
TEST_CASE("Winner")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    std::ostringstream oss;
    std::streambuf *original = std::cout.rdbuf(oss.rdbuf());
    game.printWiner();
    std::string winner = oss.str();

    // verify that the winner is presenting correct
    bool result = (winner == "Alice" || winner == "Bob" || winner == "Tie");
    CHECK(result);
    std::cout.rdbuf(original);

    if (winner == "Alice")
    {
        CHECK(p1.cardesTaken() > p2.cardesTaken());
    }
    else if (winner == "Bob")
    {
        CHECK(p1.cardesTaken() < p2.cardesTaken());
    }
    else
    {
        CHECK(p1.cardesTaken() == p2.cardesTaken());
    }
}
TEST_CASE("End")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}

TEST_CASE("Exception")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    // verify that the players won't go over or under the the amount that is legal after the game is over
    p1.setStackSize(53);
    CHECK_THROWS(p1.stacksize());

    p1.setStackSize(-1);
    CHECK_THROWS(p1.stacksize());
    p1.setCardesTaken(53);
    CHECK_THROWS(p1.cardesTaken());
    p1.setCardesTaken(-1);
    CHECK_THROWS(p1.cardesTaken());

    // verify that player name cannot be empty
    CHECK_THROWS(new Player(""));

    // verify that Game cannot have the same 2 players
    CHECK_THROWS(new Game(p1, p1));
}