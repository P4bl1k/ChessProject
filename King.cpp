#include "King.h"
#include <iostream>
#include <string>
#include <cmath>

/*
This function; constructs a King piece with specified name, type, and position.
Input: name - piece name, type - piece type, position - board position.
Output: None.
*/
King::King(const string name, const string type, const string position) : Figure(name, type, position)
{
}

/*
This function; moves the King to a new position if the move is legal.
Input: newPosition - target square.
Output: returnString - a string representing move result code.
*/
string King::move(const string newPosition)
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
This function; checks if a King's move to a position is valid (one square any direction).
Input: position - target square.
Output: true - if move is valid, false - otherwise.
*/
bool King::isLegitMove(const string position) const
{
	string currPosition = getPosition();

	bool diagonalOnce = std::abs(currPosition[1] - position[1]) == 1 && std::abs(currPosition[0] - position[0]) == 1;
	bool straightOnce = (std::abs(currPosition[0] - position[0]) == 1 && std::abs(currPosition[1] - position[1]) == 0) || (std::abs(currPosition[0] - position[0]) == 0 && std::abs(currPosition[1] - position[1]) == 1);

	if (straightOnce || diagonalOnce)
	{
		return true;
	}
	return false;
}
