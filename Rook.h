#pragma once
#include "Figure.h"

class Rook : virtual public Figure
{
public:
    Rook(std::string name, std::string position);
    bool isLegitMove(std::string newPosition) const override;
};
