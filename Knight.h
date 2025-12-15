#pragma once
#include "Figure.h"

class Knight : public Figure
{
public:
    Knight(std::string name, std::string position);

    bool isLegitMove(std::string newPosition) const override;
};
