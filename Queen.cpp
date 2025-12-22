#include "Queen.h"

/*
This function; constructs a Queen piece with specified name, type, and position.
Input: name - piece name, type - piece type, position - board position.
Output: None.
*/
Queen::Queen(const string name, const string type, const string position) : Figure(name, type, position)
{
}

/*
This function; moves the Queen to a new position if the move is legal.
Input: newPosition - target square.
Output: returnString - move result code.
*/
string Queen::move(const string newPosition)
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
This function; checks if a Queen's move to a position is valid (straight or diagonal).
Input: position - target square.
Output: ...: true - if the move is valid, false - otherwise.
*/
bool Queen::isLegitMove(const string position) const
{
	string currPosition = getPosition();

	bool diagonalMove = std::abs(currPosition[1] - position[1]) == std::abs(currPosition[0] - position[0]);
	bool straightMove = (std::abs(currPosition[0] - position[0]) >= 1 && std::abs(currPosition[1] - position[1]) == 0) || (std::abs(currPosition[0] - position[0]) == 0 && std::abs(currPosition[1] - position[1]) >= 1);

	return straightMove || diagonalMove;
}
