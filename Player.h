#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Knight.h"
#include <string>
#include <vector>

// Forward declaration to resolve circular dependency
class Board;

class Player
{
private:
    std::vector<Figure*> figures;
    bool thisPlayerTurn;
    bool isChecked;
    Board* board;

public:
    Player();

    void addFigure(Figure* newFigure);
    void removeFigure(std::string position);

    Figure* getFigureAtLocationX(const string location) const;
    std::vector<Figure*> getFigureVector();
    bool isOneOfMyFiguresAtXLocation(const string location) const;
    std::string getKingLocation() const;

    void setCheckState(bool check);
    bool isCheckedState() const;

    bool isPlayerTurn() const;
    void changeTurnState();
    Player operator=(Player& otherPlayer);

    string moveFigure(std::string source, std::string destination);

    bool destinationPosOfFigureIsMyFigure(std::string destinationPos);
    bool isOneOfMyFiguresCanReachLocation(const std::string location) const;

    std::string getPlayerString();
    bool isLegitEatingMoveForPawn(const string source, const string destination, const string name);
};

#endif
