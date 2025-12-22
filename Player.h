#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Knight.h"
#include <iostream>
#include <string>
#include <vector>

class Board;

class Player
{
    private:
        std::vector<Figure*> figures;
        bool thisPlayerTurn;
        bool isChecked;
        Board* board;

    public:
        /*
        This function; constructs a Player with default values for turn, check state, and board pointer.
        Input: None.
        Output: None.
        */
        Player();

        /*
        This function; adds a chess piece to the player's collection.
        Input: newFigure - pointer to the piece.
        Output: None.
        */
        void addFigure(Figure* newFigure);

        /*
        This function; removes a figure from the player at the given position.
        Input: position - figure location.
        Output: None.
        */
        void removeFigure(std::string position);

        /*
        This function; returns the figure located at a specific board position.
        Input: location - board position.
        Output: Figure* - pointer to figure or nullptr.
        */
        Figure* getFigureAtLocationX(const string location) const;

        /*
        This function; returns the player's list of figures.
        Input: None.
        Output: vector<Figure*> - figures collection.
        */
        std::vector<Figure*> getFigureVector();

        /*
        This function; checks if the player has a figure at a given position.
        Input: location - board position.
        Output: true - if a figure stands there, false - otherwise.
        */
        bool isOneOfMyFiguresAtXLocation(const string location) const;

        /*
        This function; returns the current position of the player's King.
        Input: None.
        Output: ... - king position.
        */
        std::string getKingLocation() const;

        /*
        This function; sets the player's check state.
        Input: check - check status.
        Output: None.
        */
        void setCheckState(bool check);

        /*
        This function; checks if the player is currently in check.
        Input: None.
        Output: isChecked: true - if in checked state, false - otherwise.
        */
        bool isCheckedState() const;

        /*
        This function; checks if it is this player's turn.
        Input: None.
        Output: thisPlayerTurn: true - if it is, false - otherwise.
        */
        bool isPlayerTurn() const;

        /*
        This function; toggles the player's turn state.
        Input: None.
        Output: None.
        */
        void changeTurnState();

        /*
        This function; assigns another player's state to this player.
        Input: otherPlayer - source player.
        Output: ... - assigned player object.
        */
        Player operator=(Player& otherPlayer);

        /*
        This function; moves a player's figure from source to destination if the move is legal.
        Input: sourcePosOfPiece - starting square, destinationPosOfPiece - target square.
        Output: returnString - move result code.
        */
        string moveFigure(std::string source, std::string destination);

        /*
        This function; checks if a destination position is occupied by the player's own figure.
        Input: destinationPos - target square.
        Output: ...: true - if occupied by the player's own figure, false - otherwise.
        */
        bool destinationPosOfFigureIsMyFigure(std::string destinationPos);

        /*
        This function; checks if any of the player's figures can legally reach a given location.
        Input: location - target square.
        Output: true - if reachable, false - otherwise.
        */
        bool isOneOfMyFiguresCanReachLocation(const std::string location) const;

        /*
        This function; returns a string representation of all the player's figures and their positions.
        Input: None.
        Output: result - figures and positions.
        */
        std::string getPlayerString();

        /*
        This function; checks if a pawn's capture move from source to destination is legal.
        Input: source - start square, destination - target square, name - pawn name.
        Output: true - if the capture is legal, false - otherwise.
        */
        bool isLegitEatingMoveForPawn(const string source, const string destination, const string name);
};

#endif
