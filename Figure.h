#pragma once
#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <string>

class Figure
{
    protected:
        std::string name;
        std::string type;
        std::string position;
        bool isItFirstPawnMove;

    public:
        /*
        This function; is a constructor that creates a figure with the given name, type and position.
        Input: name - the figure name, type - the figure type, position - the board position.
        Output: None.
        */
        Figure(std::string name, std::string type, std::string position);

        /*
        This function; sets the name of the figure.
        Input: name - the new name.
        Output: None.
        */
        void setName(std::string name);

        /*
        This function; sets the type of the figure.
        Input: type - the new type.
        Output: None.
        */
        void setType(std::string type);

        /*
        This function; sets the position of the figure on the board.
        Input: newPosition - the new board position.
        Output: None.
        */
        void setPosition(std::string newPosition);

        /*
        This function; moves the figure to a new position on the board.
        Input: newPosition - the destination position.
        Output: None.
        */
        void move(std::string newPosition);

        /*
        This function; checks if a move to the given position is basically valid.
        Input: position - the destination position.
        Output: true  - if the move is valid, false - otherwise.
        */
        virtual bool isLegitMove(std::string position) const = 0;
        /*
        This function; returns the current position of the figure.
        Input: None.
        Output: position - the figure position.
        */
        std::string getPosition() const;

        /*
        This function; returns the name of the figure.
        Input: None.
        Output: name - the figure name.
        */
        std::string getName() const;

        /*
        This function; returns the type of the figure.
        Input: None.
        Output: type - the figure type.
        */
        std::string getType() const;

        /*
        This function; destroys the figure object.
        Input: None.
        Output: None.
        */
        virtual ~Figure() = default;
};

#endif