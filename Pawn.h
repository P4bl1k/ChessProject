#pragma once
#ifndef PAWN_H
#define PAWN_H
#include "Figure.h"

class Pawn : public Figure
{
	public:
		/*
		This function; constructs a Pawn piece with specified name, type, and position and sets initial move state.
		Input: name - piece name, type - piece type, position - board position.
		Output: None.
		*/
		Pawn(const string name, const string type, const string position);

		/*
		This function; moves the Pawn to a new position if the move or capture is legal.
		Input: newPosition - target square.
		Output: returnString - a string representing the move result code.
		*/
		virtual string move(const string newPosition) override;

		/*
		This function; checks if a Pawn's forward move to a position is valid.
		Input: position - target square.
		Output: straightOnce - true if the move is valid, false - otherwise.
		*/
		virtual bool isLegitMove(const string position) const override;

		/*
		This function; checks if a Pawn's diagonal capture move is valid.
		Input: position - target square.
		Output: diagonalOnce - true if the capture move is valid, false otherwise.
		*/
		bool isLegitEatingMove(const string position) const;
};

#endif