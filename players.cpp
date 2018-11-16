
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "players.h"

using namespace std;

// inherits from Player class and returns user input
int HumanPlayer::getNextTurn(Game game)
{
	int i;
	cin >> i;
	return i;
};

// inherits from Player class and finds and returns a random number between 1 and 7
int AiPlayer::getNextTurn(Game game)
{
	int j;
	j = rand() % 7 + 1;
	srand(time(NULL));
	cout << j << "\n";
	return j;
};
