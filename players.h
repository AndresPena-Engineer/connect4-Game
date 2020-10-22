// Header class for constructors of the connect4 game
#ifndef LAB7_PLAYERS_H
#define LAB7_PLAYERS_H

#include "game.h"

class Game;

// this is an abstract class
class Player
{
// to make an abstract class you must set a virtual function to 0 to be pure virtual
public:
	virtual int getNextTurn(Game game) = 0;
};

// class HumanPlayer inherits from Player class
class HumanPlayer : public Player
{
public:
	int getNextTurn(Game game);
};

// class AiPlayer inherits from Player class
class AiPlayer : public Player
{
public:
	int getNextTurn(Game game);
};

#endif //LAB7_PLAYERS_H
