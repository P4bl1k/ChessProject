#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H
#include "Figure.h"

class Knight : public Figure
{
	public:
		/*
		This function; constructs a Knight piece with specified name, type, and position.
		Input: name - piece name, type - piece type, position - board position.
		Output: None.
		*/
		Knight(const string name, const string type, const string position);

		/*
		This function; moves the Knight to a new position if the move is legal.
		Input: newPosition - target square.
		Output: returnString - a string representng the move result code.
		*/
		virtual string move(const string newPosition) override;

		/*
		This function; checks if a Knight's move to a position follows L-shaped movement rules.
		Input: position - target square.
		Output: true - if the move is valid, false - otherwise.
		*/
		virtual bool isLegitMove(const string position) const override;
};

#endif
