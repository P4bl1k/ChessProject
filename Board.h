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
    Board();

    bool isWhiteTurn() const;
    bool isBlackTurn() const;

    std::string getBoardString() const;
    void setBoardString(const std::string newBoard);

    void printBoard() const;

    void eatPiece(const std::string position);
    bool isSquareTaken(const std::string position) const;

    std::string movePieceAtBoard(const std::string source, const std::string destination);

    void updateBoardString();


    bool isKingChecked();

    Figure* createFigure(const std::string name, const std::string type, const std::string position);

    bool isOneOfBlackPiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const;
    bool isOneOfWhitePiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const;

    bool isThereAnInterrupterPieceAtPath(std::string srcPosition, std::string destPosition) const;

private:
    Player blackSide;
    Player whiteSide;
    std::string board;

    void changeTurn();
};

#endif
