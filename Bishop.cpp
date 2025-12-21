#include "Bishop.h"

Bishop::Bishop(const string name, const string type, const string position) : Figure(name, type, position)
{
}
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
bool Bishop::isLegitMove(const string position) const
{
	string currPosition = getPosition();

	if (std::abs(currPosition[0] - position[0]) != std::abs(currPosition[1] - position[1]))
	{
		return false;
	}

	return true;
}