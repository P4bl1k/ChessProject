#pragma once
#include "Figure.h"

class Knight : public Figure
{
public:
	Knight(const string name, const string type, const string position);
	virtual string move(const string newPosition) override;
	virtual bool isLegitMove(const string position) const override;
};