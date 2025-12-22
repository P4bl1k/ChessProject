#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

class Board
{
    public:
        /*
        This function; is a constructor that initializes the chess board with pieces in their starting positions.
        Input: None.
        Output: None.
        */
        Board();

        /*
        This function; checks if it is white's turn to play.
        Input: None.
        Output: true  - if it is white's turn, false - otherwise.
        */
        bool isWhiteTurn() const;

        /*
        This function; checks if it is black turn to play.
        Input: None.
        Output: true - if it is black's turn, false - otherwise.
        */
        bool isBlackTurn() const;

        /*
        This function; returns the current board state as a string.
        Input: None.
        Output: board - string board representation.
        */
        std::string getBoardString() const;

        /*
        This function; sets the board string to a new value.
        Input: newBoard - updated board state.
        Output: None.
        */
        void setBoardString(const std::string newBoard);

        /*
        This function; prints the current board to the console.
        Input: None.
        Output: None.
        */
        void printBoard() const;

        /*
        This function; removes an opponent piece from the given board position.
        Input: position - board position.
        Output: None.
        */
        void eatPiece(const std::string position);

        /*
        This function; checks if a board square is occupied.
        Input: position - board position.
        Output: true - if the square is occupied, false - otherwise.
        */
        bool isSquareTaken(const std::string position) const;

        /*
        This function; moves a piece from a source to a destination while validating legality.
        Input: source - starting square, destination - target square.
        Output: resString - move status code.
        */
        std::string movePieceAtBoard(const std::string source, const std::string destination);

        /*
        This function; updates the board string to reflect current piece positions.
        Input: None.
        Output: None.
        */
        void updateBoardString();

        /*
        This function; checks if the current player's king is in check.
        Input: None.
        Output: true - if the king is in check, false - otherwise.
        */
        bool isKingChecked();

        /*
        This function; creates a chess piece object based on type and position.
        Input: name - piece name, type - piece type, position - board position.
        Output: Figure* - pointer to the created piece.
        */
        Figure* createFigure(const std::string name, const std::string type, const std::string position);

        /*
        This function; checks if any black piece can legally reach a destination square.
        Input: srcPosition - start square, destPosition - target square.
        Output: true - if reachable, false - otherwise.
        */
        bool isOneOfBlackPiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const;
        
        /*
        This function; checks if any white piece can legally reach a destination square.
        Input: srcPosition - start square, destPosition - target square.
        Output: true - if reachable, false - otherwise.
        */
        bool isOneOfWhitePiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const;
        
        /*
        This function; checks if any piece blocks the path between two squares.
        Input: srcPosition - start square, destPosition - target square.
        Output: true - if a piece blocks the path, false - otherwise.
        */
        bool isThereAnInterrupterPieceAtPath(std::string srcPosition, std::string destPosition) const;

    private:
        Player blackSide;
        Player whiteSide;
        std::string board;

        /*
        This function; switches the turn between white and black players.
        Input: None.
        Output: None.
        */
        void changeTurn();
};

#endif
