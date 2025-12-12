#pragma once
#include <vector>
#include <string>
#include "Figure.h"
#include "Player.h"
using namespace std;

class Board {
    public:
        Board();
        
        bool isWhiteTurn() const;
        bool isBlackTurn() const;
        string getBoard() const;
        void setBoard(string newBoard);
        void printBoard() const;
        void eatFigure(string position);
        bool isSquareTaken(string position) const;
        bool isKingChecked() const;
        bool moveFigureAtBoard(string source, string destination);
        string updatedBoardString() const;
        void createFigure(string name, string type, string position);
        bool isOneOfBlackFiguresCanReachLocationX(string source, string destination) const;
        bool isOneOfWhiteFiguresCanReachLocationX(string source, string destination) const;
        bool isThereInterupterFigureAtPath(string source, string destination) const;
        void changeTurn();
        
    private:
        // Player blackSide;
        // Player whiteSide;
        string board;
};