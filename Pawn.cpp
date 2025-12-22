#include "Pawn.h"

/*
This function; constructs a Pawn piece with specified name, type, and position and sets initial move state.
Input: name - piece name, type - piece type, position - board position.
Output: None.
*/
Pawn::Pawn(const string name, const string type, const string position) : Figure(name, type, position)
{
	changePawnMove(true);
}

/*
This function; moves the Pawn to a new position if the move or capture is legal.
Input: newPosition - target square.
Output: returnString - a string representing the move result code.
*/
string Pawn::move(const string newPosition)
{
	string returnString = to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
	if (isLegitMove(newPosition) || isLegitEatingMove(newPosition))
	{
		if (isItFirstMove())
		{
			changePawnMove(false);
		}
		setPosition(newPosition);
		returnString = to_string(LEGALMOVE);
	}

	return returnString;
}

/*
This function; checks if a Pawn's forward move to a position is valid.
Input: position - target square.
Output: straightOnce - true if the move is valid, false - otherwise.
*/
bool Pawn::isLegitMove(const string position) const
{
	string currPosition = getPosition();
	bool straightOnce = false;

	if (isItFirstMove()) //Black/White forward direction differs by name.
	{
		if (this->getName() == "P")
		{
			straightOnce = (((currPosition[1] - position[1]) == -2) || ((currPosition[1] - position[1]) == -1))
				&& ((currPosition[0] - position[0]) == 0);
		}
		else
		{
			straightOnce = (((currPosition[1] - position[1]) == 2) || ((currPosition[1] - position[1]) == 1))
				&& ((currPosition[0] - position[0]) == 0);
		}
	}
	else
	{
		if (this->getName() == "P")
		{
			straightOnce = (currPosition[1] - position[1] == -1) && (currPosition[0] - position[0] == 0);
		}
		else
		{
			straightOnce = (currPosition[1] - position[1] == 1) && (currPosition[0] - position[0] == 0);
		}
	}

	return straightOnce;
}

/*
This function; checks if a Pawn's diagonal capture move is valid.
Input: position - target square.
Output: diagonalOnce - true if the capture move is valid, false otherwise.
*/
bool Pawn::isLegitEatingMove(const string position) const
{
	string currPosition = getPosition();

	bool diagonalOnce = false;

	if (getName() == "P") //black can eat 1 diagonal forward which is backward for white.
	{
		diagonalOnce = currPosition[1] - position[1] == -1 && std::abs(currPosition[0] - position[0]) == 1;
	}
	else
	{
		diagonalOnce = currPosition[1] - position[1] == 1 && std::abs(currPosition[0] - position[0]) == 1;
	}

	return diagonalOnce;
}
