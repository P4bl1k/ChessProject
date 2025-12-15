#include "Bishop.h"
#include <cmath>

Bishop::Bishop(std::string name, std::string position)
    : Figure(name, "Bishop", position)
{
}

bool Bishop::isLegitMove(std::string newPosition) const
{
    return abs(newPosition[0] - position[0]) ==
           abs(newPosition[1] - position[1]);
}
