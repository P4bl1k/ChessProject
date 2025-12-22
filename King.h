#pragma once
#ifndef KING_H
#define KING_H
#include "Figure.h"
#include <iostream>
#include <string>
#include <cmath>

class King : public Figure
{
    public:
        /*
        This function; constructs a King piece with specified name, type, and position.
        Input: name - piece name, type - piece type, position - board position.
        Output: None.
        */
        King(const string name, const string type, const string position);

        /*
        This function; moves the King to a new position if the move is legal.
        Input: newPosition - target square.
        Output: returnString - a string representing move result code.
        */
        virtual string move(const string newPosition) override;

        /*
        This function; checks if a King's move to a position is valid (one square any direction).
        Input: position - target square.
        Output: true - if move is valid, false - otherwise.
        */
        virtual bool isLegitMove(const string position) const override;
};

#endif
