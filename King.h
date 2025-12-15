#pragma once
#include "Figure.h"

class King : public Figure
{
public:
    King(std::string name, std::string position);

    bool isLegitMove(std::string newPosition) const override;
};
