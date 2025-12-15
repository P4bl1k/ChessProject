#include "Rook.h"

Rook::Rook(std::string name, std::string position)
    : Figure(name, "Rook", position)
{
}

bool Rook::isLegitMove(std::string newPosition) const
{
    return newPosition[0] == position[0] ||
           newPosition[1] == position[1];
}
