#include "Knight.h"

/*
This function; constructs a Knight piece with specified name, type, and position.
Input: name - piece name, type - piece type, position - board position.
Output: None.
*/
Knight::Knight(const string name, const string type, const string position) : Figure(name, type, position)
{
}

/*
This function; moves the Knight to a new position if the move is legal.
Input: newPosition - target square.
Output: returnString - a string representng the move result code.
*/
string Knight::move(const string newPosition)
{
	string returnString = to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);

	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		returnString = to_string(LEGALMOVE);
	}

	return returnString;
}

/*
This function; checks if a Knight's move to a position follows L-shaped movement rules.
Input: position - target square.
Output: true - if the move is valid, false - otherwise.
*/
bool Knight::isLegitMove(const string position) const
{
	string currPosition = getPosition();

	bool topLeftRight = currPosition[0] - position[0] == 1 && currPosition[1] - position[1] == -2;
	bool topLeftLeft = currPosition[0] - position[0] == 2 && currPosition[1] - position[1] == -1;
	bool topLeft = topLeftLeft || topLeftRight;

	bool topRightLeft = currPosition[0] - position[0] == -1 && currPosition[1] - position[1] == -2;
	bool topRightRight = currPosition[0] - position[0] == -2 && currPosition[1] - position[1] == -1;
	bool topRight = topRightLeft || topRightRight;


	bool bottomRightLeft = currPosition[0] - position[0] == -1 && currPosition[1] - position[1] == 2;
	bool bottomRightRight = currPosition[0] - position[0] == -2 && currPosition[1] - position[1] == 1;
	bool bottomRight = bottomRightLeft || bottomRightRight;


	bool bottomLeftLeft = currPosition[0] - position[0] == 2 && currPosition[1] - position[1] == 1;
	bool bottomLeftRight = currPosition[0] - position[0] == 1 && currPosition[1] - position[1] == 2;
	bool bottomLeft = bottomLeftLeft || bottomLeftRight;


	return bottomLeft || bottomRight || topRight || topLeft;
}
