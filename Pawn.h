#pragma once
#include "Figure.h"

class Pawn : public Figure
{
public:
	Pawn(const string name, const string type, const string position);
	virtual string move(const string newPosition) override;
	virtual bool isLegitMove(const string position) const override;
	bool isLegitEatingMove(const string position) const;
};