#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "Figure.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Board
{
    public:
        /*
        This function; is the constructor for the board class.
        input: None.
        output: None.
        */
        Board();

        /*
        This function; checks if it's white's turn.
        input: None.
        output: True - if it's white's turn, False - otherwise.
        */
        bool isWhiteTurn() const;

        /*
        This function; check if it's black's turn.
        input: None.
        output: True - if it's black's turn, False - otherwise.
        */
        bool isBlackTurn() const;

        /*
        This function; returns the current board representation as a string.
        input: None.
        output: board - a string representing the board and current turn.
        */
        string getBoard() const;

        /*
        This function; sets the board to a new board state, it must be must be exactly 65 characters long.
        input: newBoard - a string representing the new board.
        output: None.
        */
        void setBoard(string newBoard);

        /*
        This function; prints the chess board.
        input: None.
        output: None.
        */
        void printBoard() const;

        /*
        This function; removes a figure from the board at the given position.
        input: position - a string representing the board position.
        output: None.
        */
        void eatFigure(string position);

        /*
        This function checks whether a square on the board is occupied.
        input: position - a string representing the board position.
        output: True - if the square is taken, False - otherwise.
        */
        bool isSquareTaken(string position) const;

        /*
        This function; checks whether the king is currently in check. ***Placeholder... ***Check documentation for mistakes...
        input: None.
        output: ???
        */
		bool isKingChecked() const; //TODO...

        /*
        This function moves a figure from a source square to a destination square -> ***Check documentation for mistakes...
        -> It checks if the move is valid regarding path blocking and source validity.
        input: source - starting position in chess notation, destination - target position in chess notation.
        output: True - if the move was successful, False - otherwise.
        */
		bool moveFigureAtBoard(string source, string destination); //Check for mistakes in documentation...

        /*
        This function; returns an updated board string. ***Placeholder... ***Check documentation for mistakes...
        input: None
        output: The current board string.
        */
        string updatedBoardString() const; //TODO...

        /*
        This function; creates a figure on the board. ***Placeholder... ***Check documentation for mistakes...
        input: name - name of the figure, type - type of the figure, position - position in chess.
        output: None
        */
		void createFigure(string name, string type, string position); //TODO...

        /*
        This function; checks if any black figure can reach a given location. ***Placeholder... ***Check documentation for mistakes...
        input: source - starting position, destination - target position.
        output: ???
        */
		bool isOneOfBlackFiguresCanReachLocationX(string source, string destination) const; //TODO...

        /*
        This function checks if any white figure can reach a given location. ***Placeholder... ***Check documentation for mistakes...
        input: source - starting position, destination - target position.
        output: ???
        */
		bool isOneOfWhiteFiguresCanReachLocationX(string source, string destination) const; //TODO...

        /*
        This function; checks if there is any figure blocking the path -> ***Check documentation for mistakes...
        -> between a source and destination square, knights are excluded since they can jump over other pieces.
        input: source - starting position in chess notation, destination - target position in chess notation.
        output: True - if there is a blocking figure, False - otherwise.
        */
		bool isThereInterupterFigureAtPath(string source, string destination) const; //Check for mistakes in documentation...

        /*
        This function; switches the turn between white and black, If it is white's turn, it becomes black's turn and opposite.
        input: None.
        output: None.
        */
        void changeTurn();
        
    private:
        //Player blackSide;
        //Player whiteSide;
        string board;
};

#endif
