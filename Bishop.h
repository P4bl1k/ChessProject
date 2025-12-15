#pragma once
#include "Figure.h"

class Bishop : public Figure
{
public:
    Bishop(std::string name, std::string position);

    bool isLegitMove(std::string newPosition) const override;
};
