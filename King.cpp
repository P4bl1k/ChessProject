#include "King.h"
#include <cmath>

King::King(std::string name, std::string position)
    : Figure(name, "King", position)
{
}

bool King::isLegitMove(std::string newPosition) const
{
    int dx = abs(newPosition[0] - position[0]);
    int dy = abs(newPosition[1] - position[1]);

    return dx <= 1 && dy <= 1 && !(dx == 0 && dy == 0);
}
