#include "Rook.h"

Rook::Rook(const string name, const string type, const string position) : Figure(name, type, position)
{
}
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
bool Rook::isLegitMove(const string position) const
{
	string currPosition = getPosition();

	//if someone tried to make an unhorizontal/diagonal move with the rook
	if (currPosition[0] != position[0] && currPosition[1] != position[1])
	{
		return false;
	}

	return true;
}