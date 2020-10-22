#include <iostream>
#include "game.h"

using namespace std;

// constructor for an object of type Game
Game::Game(Player &p1, Player &p2)
{
	play1 = &p1;
	play2 = &p2;
};

// returns the current GameState state of an object of type Game
GameState Game::getState()
{
	return state;
};

// returns false if there is a draw or either of the players has won
bool Game::isRunning()
{
	if (state == Draw || state == P1Won || state == P2Won)
	{
		return false;
	}
	else
	{
		return true;
	}
};

// operator() overrides to return an object of enumerated type BoardField within a 2 dimensional array
BoardField Game::operator()(int x, int y)const
{
	if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight)
	{
		return board[x][y];
	}

	else
	{
		return Empty;
	}
};

// this is where the game board is updated, also where a winning play is checked on the board
void Game::nextTurn()
{
	// counter used to declare draw if number of turns is greater than 42 because there are only 42 slots on the board
	counter++;

	if (counter == 43)
	{
		state = Draw;
	}

	// this is what happens if it is player 1's turn
	if (state == TurnP1)
	{
		// store the value of the spot where turn player wants to place a stone
		thisTurn1 = (play1->getNextTurn(*this) - 1);

		// catches invalid input
		while (board[thisTurn1][0] != Empty)
		{
			cout << "Invalid input: try again\n";
			thisTurn1 = (play1->getNextTurn(*this) - 1);
		}

		// these if else statements change the board from bottom up 
		// so it is not repetative and it picks a different spot to drop 
		if (board[thisTurn1][5] == Empty)
		{
			board[thisTurn1][5] = Player1;
		}
		else if (board[thisTurn1][4] == Empty)
		{
			board[thisTurn1][4] = Player1;
		}
		else if (board[thisTurn1][3] == Empty)
		{
			board[thisTurn1][3] = Player1;
		}
		else if (board[thisTurn1][2] == Empty)
		{
			board[thisTurn1][2] = Player1;
		}
		else if (board[thisTurn1][1] == Empty)
		{
			board[thisTurn1][1] = Player1;
		}
		else if (board[thisTurn1][0] == Empty)
		{
			board[thisTurn1][0] = Player1;
		}

		// changes gamestate for player 2 to have a turn
		state = TurnP2;

		// checks for a win condition on the board, and if there is a win, gamestate is 
		// switched to turn player winning
		for (int x = 0; x < 7; x++)
		{
			for (int y = 0; y < 6; y++) {

				// checks board for a vertical win
				if (board[x][y] == Player1 && board[x][y + 1] == Player1 &&
					board[x][y + 2] == Player1 && board[x][y + 3] == Player1)
				{
					state = P1Won;
				}
				// checks board for horizontal win
				else if (board[x][y] == Player1 && board[x + 1][y] == Player1 &&
					board[x + 2][y] == Player1 && board[x + 3][y] == Player1)
				{
					state = P1Won;
				}
				// checks board for a bottom right diagonal win
				else if (board[x][y] == Player1 && board[x + 1][y + 1] == Player1 &&
					board[x + 2][y + 2] == Player1 && board[x + 3][y + 3] == Player1)
				{
					state = P1Won;
				}
				// checks board for a bottom left diagonal win
				else if (board[x][y + 3] == Player1 && board[x + 1][y + 2] == Player1 &&
					board[x + 2][y + 1] == Player1 && board[x + 3][y] == Player1)
				{
					state = P1Won;
				}
			}
		}
	}

	// this is what happens if it is player 2's turn
	else if (state == TurnP2)
	{
		// store the value of the spot where turn player wants to place a stone
		thisTurn2 = (play2->getNextTurn(*this) - 1);

		// catches invalid input
		while (board[thisTurn2][0] != Empty)
		{
			cout << "Invalid input: try again\n";
			thisTurn2 = (play2->getNextTurn(*this) - 1);
		}

		// these if else statements change the board from bottom up because the stones fall to the lowest slot
		if (board[thisTurn2][5] == Empty)
		{
			board[thisTurn2][5] = Player2;
		}
		else if (board[thisTurn2][4] == Empty)
		{
			board[thisTurn2][4] = Player2;
		}
		else if (board[thisTurn2][3] == Empty)
		{
			board[thisTurn2][3] = Player2;
		}
		else if (board[thisTurn2][2] == Empty)
		{
			board[thisTurn2][2] = Player2;
		}
		else if (board[thisTurn2][1] == Empty)
		{
			board[thisTurn2][1] = Player2;
		}
		else if (board[thisTurn2][0] == Empty)
		{
			board[thisTurn2][0] = Player2;
		}

		// change gamestate for player 1 to have a turn
		state = TurnP1;

		// these for loops check for a win condition on the board, 
		// and if there is a win, gamestate is switched to turn player winning
		for (int x = 0; x < 7; x++)
		{
			for (int y = 0; y < 6; y++) {

				// checks board for a vertical win
				if (board[x][y] == Player2 && board[x][y + 1] == Player2 &&
					board[x][y + 2] == Player2 && board[x][y + 3] == Player2)
				{
					state = P2Won;
				}
				// checks board for horizontal win
				else if (board[x][y] == Player2 && board[x + 1][y] == Player2 &&
					board[x + 2][y] == Player2 && board[x + 3][y] == Player2)
				{
					state = P2Won;
				}
				// checks board for a bottom right diagonal win
				else if (board[x][y] == Player2 && board[x + 1][y + 1] == Player2 &&
					board[x + 2][y + 2] == Player2 && board[x + 3][y + 3] == Player2)
				{
					state = P2Won;
				}
				// checks board for a bottom left diagonal win
				else if (board[x][y + 3] == Player2 && board[x + 1][y + 2] == Player2 &&
					board[x + 2][y + 1] == Player2 && board[x + 3][y] == Player2)
				{
					state = P2Won;
				}
			}
		}
	}
};
