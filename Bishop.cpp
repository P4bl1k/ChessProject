#include "Bishop.h"
#include <iostream>
#include <string>

/*
This function; is a constructor that creates a bishop with the given name, type and position.
Input: name - the figure name, type - the figure type, position - the board position.
Output: None.
*/
Bishop::Bishop(const string name, const string type, const string position) : Figure(name, type, position)
{
}

/*
This function; moves the bishop to a new position on the board.
Input: newPosition - the destination position.
Output: returnString - a string representing the result of the move attempt.
*/
string Bishop::move(const string newPosition)
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
This function; checks if a move to the given position is basically valid for a bishop.
Input: position - the destination position.
Output: true  - if the move is valid, false - otherwise.
*/
bool Bishop::isLegitMove(const string position) const
{
	string currPosition = getPosition();

	if (std::abs(currPosition[0] - position[0]) != std::abs(currPosition[1] - position[1]))
	{
		return false;
	}

	return true;
}
