#pragma once
#include "Figure.h"
#include "Board.h"

class Pawn : public Figure
{
private:
    Board* board;

public:
    Pawn(string name, string position, Board* board);

    bool isLegitMove(string newPosition) const override;
};
