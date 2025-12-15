#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Figure.h"
#include "Board.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
    private:
        vector<Figure*> figures;
        bool thisPlayerTurn;
        bool isChecked;
        Board* board;

    public:
        /*
        This function; is the constructor for the Player class, it initializes the player with a pointer to the board ->
        -> sets the turn state to false and the check state to false.
        input: board - pointer to the game board.
        output: None.
        */
        Player(Board* board);

        /*
        This function; is the destructor for the Player class, it deletes all dynamically allocated figures owned by the player.
        input: None.
        output: None.
        */
        ~Player();

        /*
        This function; adds a new figure to the player's figure list.
        input: newFigure - pointer to the figure to add.
        output: None.
        */
        void addFigure(Figure* newFigure);

        /*
        This function; removes a figure from the player by its board position.
        input: position - position of the figure in chess notation.
        output: None.
        */
        void removeFigure(string position);

        /*
        This function; returns the figure located at a given position.
        input: location - board position in chess notation
        output: f / ... - pointer to the figure if found, nullptr otherwise.
        */
        Figure* getFigureAtLocationX(string location);

        /*
        This function; returns the vector containing all the player's figures.
        input: None.
        output: figures - a vector of pointers to Figure objects.
        */
        vector<Figure*> getFigureVector();

        /*
        This function; returns the current location of the player's king.
        input: None.
        output: ... - position of the king as a string, or empty string if not found.
        */
        string getKingLocation();

        /*
        This function; sets the player's check state.
        input: check: True - if the player is in check, False - otherwise.
        output: None.
        */
        void setCheckState(bool check);

        /*
        This function; checks whether the player is currently in check.
        input: None.
        output: isChecked: True - if the player is in check, False - otherwise.
        */
        bool isCheckedState() const;

        /*
        This function checks whether it is currently this player's turn.
        input: None.
        output: thisPlayerTurn: True - if it is the player's turn, False - otherwise.
        */
        bool isPlayerTurn();

        /*
        This function switches the player's turn state.
        input: None.
        output: None.
        */
        void changeTurnState();

        /*
        This function moves one of the player's figures from source to destination, it validates the move using the figure and the board.
        input: source - starting position, destination - target position.
        output: True - if the move was successful, False - otherwise.
        */
        bool moveFigure(string source, string destination);

        /*
        This function checks if one of the player's figures is located at the given position.
        input: location - board position in chess notation.
        output: True - if a figure exists at the location, False - otherwise.
        */
        bool isOneOfMyFiguresAtXLocation(string location);

        /*
        This function checks if the destination position contains one of the player's own figures.
        input: destinationPos - destination board position.
        output: True if the destination contains the player's figure.
        */
        bool destinationPosOfFigureIsMyFigure(string destinationPos);

        /*
        This function checks if any of the player's figures can reach the given location.
        input: location - target board position.
        output: True - if at least one figure can reach the location, False - otherwise.
        */
        bool isOneOfMyFiguresCanReachLocation(const string location);

        /*
        This function returns a string representation of the player's figures.
        input: None.
        output: result - a string describing all the player's figures.
        */
        string getPlayerString();
};

#endif
