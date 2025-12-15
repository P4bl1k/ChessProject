#include "Knight.h"
#include <cmath>

Knight::Knight(std::string name, std::string position)
    : Figure(name, "Knight", position)
{
}

bool Knight::isLegitMove(std::string newPosition) const
{
    int dx = abs(newPosition[0] - position[0]);
    int dy = abs(newPosition[1] - position[1]);

    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}
