#include "Pawn.h"
#include <cmath>

Pawn::Pawn(string name, string position, Board* board)
    : Figure(name, "Pawn", position), board(board)
{
}

bool Pawn::isLegitMove(string newPosition) const 
{
    int colDiff = newPosition[0] - position[0];
    int rowDiff = newPosition[1] - position[1];

    bool isWhite = (name[0] == 'W' || name[0] == 'P');
    int direction = isWhite ? 1 : -1;


    if (colDiff == 0 && rowDiff == direction &&
        !board->isSquareTaken(newPosition))
        return true;

    // double move
    if (colDiff == 0 && rowDiff == 2 * direction &&
        isItFirstPawnMove)
        return true;

    // capture
    if (abs(colDiff) == 1 && rowDiff == direction &&
        board->isSquareTaken(newPosition))
        return true;

    // EN PASSANT
    if (abs(colDiff) == 1 && rowDiff == direction &&
        newPosition == board->getLastPawnDoubleMove())
        return true;

    return false;
}
