///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: Andres Pena
// Description: 
// 			This was a lab was created as a Connect 4 game. Capable of playing (Human vs Human, Human vs AI, and Computer vs Computer).
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Libraries
#include <iostream>

#include "players.h"
#include "game.h"

using namespace std;

// Getters for players (AI and Human player)
Player* getPlayer()
{
	static int playerNumber = 1;

	int input;
	for (input = 0; input != 1 && input != 2;)
	{
		cout << "Select Player " << playerNumber << " (human: 1, ai: 2) ";
		cin >> input;
	}

	playerNumber++;

	if (input == 1)
	{
		return new HumanPlayer;
	}
	else // input == 2
	{
		return new AiPlayer;
	}

}

// Method to create and display the X's and O'x of each position that are being placed in the game
void PrintBoard(const Game &game)
{
	cout << endl;

	// Printing the matrix of the board
	for (int y = 0; y < game.BoardHeight; y++)
	{
		cout << "  | ";
		for (int x = 0; x < game.BoardWidth; x++)
		{
			char boardChar;
			switch (game(x, y))
			{
			case BoardField::Empty:
				boardChar = ' ';
				break;
			case BoardField::Player1:
				boardChar = 'O';
				break;
			case BoardField::Player2:
				boardChar = 'X';
				break;
			}
			cout << boardChar << ' ';
		}
		cout << "|\n";
	}

	cout << "  ---";
	for (int x = 0; x < game.BoardWidth; x++)
	{
		cout << "--";
	}
	cout << endl;

	cout << "   ";
	for (int x = 0; x < game.BoardWidth; x++)
	{
		cout << " " << x + 1;
	}
	cout << endl << endl;

}

// Main class to call and create the board.
int main()
{
	cout << "* * * * * * * * * * * * *\n";
	cout << "  Welcome to Connect 4!\n\n";

	Player* player1 = getPlayer();
	Player* player2 = getPlayer();

	Game game(*player1, *player2);

	while (game.isRunning())
	{
		PrintBoard(game);

		int curPlayer;

		switch (game.getState())
		{
		case GameState::TurnP1:
			curPlayer = 1;
			break;
		case GameState::TurnP2:
			curPlayer = 2;
			break;
		}

		cout << "Turn for Player " << curPlayer << ": ";

		game.nextTurn();
	}

	PrintBoard(game);

	// Decision to who won the game
	switch (game.getState())
	{
	case GameState::P1Won:
		cout << "Player 1 won the game!";
		break;
	case GameState::P2Won:
		cout << "Player 2 won the game!";
		break;
	case GameState::Draw:
		cout << "Draw, no winner.";
		break;
	}

	cout << endl;

	delete player1;
	delete player2;

	system("pause");

	return 0;
}
