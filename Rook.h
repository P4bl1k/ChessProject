#pragma once
#ifndef ROOK_H
#define ROOK_H
#include "Figure.h"

class Rook : public Figure
{
	public:
		/*
		This function; constructs a Rook piece with specified name, type, and position.
		Input: name - piece name, type - piece type, position - board position.
		Output: None.
		*/
		Rook(const string name, const string type, const string position);

		/*
		This function; moves the Rook to a new position if the move is legal.
		Input: newPosition - target square.
		Output: returnString - move result code.
		*/
		virtual string move(const string newPosition) override;

		/*
		This function; checks if a Rook's move to a position is valid (straight only).
		Input: position - target square.
		Output: true - if the move is valid, false - otherwise.
		*/
		virtual bool isLegitMove(const string position) const override;
};

#endif
