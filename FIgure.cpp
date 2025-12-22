#include "Figure.h"
#include <iostream>
#include <string>

/*
This function; is a constructor that creates a figure with the given name, type and position.
Input: name - the figure name, type - the figure type, position - the board position.
Output: None.
*/
Figure::Figure(std::string name, std::string type, std::string position)
{
    this->name = name;
    this->type = type;
    this->position = position;
    this->isItFirstPawnMove = true;
}

/*
This function; sets the name of the figure.
Input: name - the new name.
Output: None.
*/
void Figure::setName(std::string name)
{
    this->name = name;
}

/*
This function; sets the type of the figure.
Input: type - the new type.
Output: None.
*/
void Figure::setType(std::string type)
{
    this->type = type;
}

/*
This function; sets the position of the figure on the board.
Input: newPosition - the new board position.
Output: None.
*/
void Figure::setPosition(std::string newPosition)
{
    this->position = newPosition;
}

/*
This function; returns the current position of the figure.
Input: None.
Output: position - the figure position.
*/
std::string Figure::getPosition() const
{
    return this->position;
}

/*
This function; returns the name of the figure.
Input: None.
Output: name - the figure name.
*/
std::string Figure::getName() const
{
    return this->name;
}

/*
This function; returns the type of the figure.
Input: None.
Output: type - the figure type.
*/
std::string Figure::getType() const
{
    return this->type;
}

/*
This function returns if it's the first pawn move.
Input: none.
Output: this->isItFirstPawnMove field's value.
*/
bool Figure::isItFirstMove() const
{
    return this->isItFirstPawnMove;
}

/*
This function; changes the isItFirstPawnMove field to the new state.
Input: newState - the new state.
Output: None.
*/
void Figure::changePawnMove(const bool newState)
{
    this->isItFirstPawnMove = newState;
}