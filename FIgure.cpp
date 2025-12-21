#include "Figure.h"
#include <iostream>
#include <string>

Figure::Figure(std::string name, std::string type, std::string position)
{
    this->name = name;
    this->type = type;
    this->position = position;
    this->isItFirstPawnMove = true;
}
void Figure::setName(std::string name)
{
    this->name = name;
}

void Figure::setType(std::string type)
{
    this->type = type;
}

void Figure::setPosition(std::string newPosition)
{
    this->position = newPosition;
}

std::string Figure::getPosition() const
{
    return this->position;
}

std::string Figure::getName() const
{
    return this->name;
}

std::string Figure::getType() const
{
    return this->type;
}

bool Figure::isItFirstMove() const
{
    return this->isItFirstPawnMove;
}

void Figure::changePawnMove(const bool newState)
{
    this->isItFirstPawnMove = newState;
}