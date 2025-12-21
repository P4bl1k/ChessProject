#pragma once
#include "Figure.h"

class King : public Figure
{
public:
    King(const string name, const string type, const string position);
    virtual string move(const string newPosition) override;
    virtual bool isLegitMove(const string position) const override;
};
