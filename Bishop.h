#pragma once
#include "Figure.h"

class Bishop : public Figure
{
public:
    Bishop(const std::string name,const string type,const std::string position);
	virtual string move(const string newPosition) override;
	virtual bool isLegitMove(const string position) const override;
};
