#pragma once
#ifndef QUEEN_H
#define QUEEN_H
#include "Figure.h"

class Queen : public Figure
{
	public:
		/*
		This function; constructs a Queen piece with specified name, type, and position.
		Input: name - piece name, type - piece type, position - board position.
		Output: None.
		*/
		Queen(const string name, const string type, const string position);

		/*
		This function; moves the Queen to a new position if the move is legal.
		Input: newPosition - target square.
		Output: returnString - move result code.
		*/
		virtual string move(const string newPosition) override;

		/*
		This function; checks if a Queen's move to a position is valid (straight or diagonal).
		Input: position - target square.
		Output: ...: true - if the move is valid, false - otherwise.
		*/
		virtual bool isLegitMove(const string position) const override;
};

#endif
