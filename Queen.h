#pragma once
#include "Figure.h"

class Queen : public Figure
{
public:
	//methods
	Queen(const string name, const string type, const string position);
	virtual string move(const string newPosition) override;
	virtual bool isLegitMove(const string position) const override;
};