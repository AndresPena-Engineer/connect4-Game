// Header class for constructors of the connect4 game
#ifndef CS361LAB7_GAME_H
#define CS361LAB7_GAME_H

#include "players.h"

// enumerated data type for gamestate
enum GameState
{
	TurnP1, TurnP2, P1Won, P2Won, Draw
};

// enumerated data type for boardfield
enum BoardField
{
	Empty, Player1, Player2
};

class Player;

// class Game
class Game
{
public:

	const int BoardWidth = 7;

	const int BoardHeight = 6;

	Game(Player &p1, Player &p2);

	GameState getState();

	bool isRunning();

	BoardField operator() (int x, int y) const;

	void nextTurn();

private:

	// counter for draw counter to see how many turns passed
	int counter = 0;   

	// for turn player 1
	int thisTurn1;  

	// for turn player 2
	int thisTurn2;  

	// creates a pointer to an object of type player
	Player *play1;     
	Player *play2;     

	// start with player 1
	GameState state = TurnP1;     
	
	// This is the entire board set to empty
	BoardField board[7][6] = { 
	{ Empty, Empty, Empty, Empty, Empty, Empty },
	{ Empty, Empty, Empty, Empty, Empty, Empty },
	{ Empty, Empty, Empty, Empty, Empty, Empty },
	{ Empty, Empty, Empty, Empty, Empty, Empty },
	{ Empty, Empty, Empty, Empty, Empty, Empty },
	{ Empty, Empty, Empty, Empty, Empty, Empty },
	{ Empty, Empty, Empty, Empty, Empty, Empty } 
	
	};

};

#endif //CS361LAB7_GAME_H
