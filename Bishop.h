#pragma once
#ifndef BISHOP_H
#define BISHOP_H
#include "Figure.h"
#include <iostream>
#include <string>

class Bishop : public Figure
{
	public:
		/*
		This function; is a constructor that creates a bishop with the given name, type and position.
		Input: name - the figure name, type - the figure type, position - the board position.
		Output: None.
		*/
		Bishop(const std::string name,const string type,const std::string position);

		/*
		This function; moves the bishop to a new position on the board.
		Input: newPosition - the destination position.
		Output: returnString - a string representing the result of the move attempt.
		*/
		virtual string move(const string newPosition) override;

		/*
		This function; checks if a move to the given position is basically valid for a bishop.
		Input: position - the destination position.
		Output: true  - if the move is valid, false - otherwise.
		*/
		virtual bool isLegitMove(const string position) const override;
};

#endif
