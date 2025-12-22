#include "Rook.h"

/*
This function; constructs a Rook piece with specified name, type, and position.
Input: name - piece name, type - piece type, position - board position.
Output: None.
*/
Rook::Rook(const string name, const string type, const string position) : Figure(name, type, position)
{
}

/*
This function; moves the Rook to a new position if the move is legal.
Input: newPosition - target square.
Output: returnString - move result code.
*/
string Rook::move(const string newPosition)
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
This function; checks if a Rook's move to a position is valid (straight only).
Input: position - target square.
Output: true - if the move is valid, false - otherwise.
*/
bool Rook::isLegitMove(const string position) const
{
	string currPosition = getPosition();

	if (currPosition[0] != position[0] && currPosition[1] != position[1]) //if someone tried to make an unhorizontal/diagonal move with the rook.
	{
		return false;
	}

	return true;
}
