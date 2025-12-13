#pragma once
#include <vector>
#include <string>
#include "Figure.h"
using namespace std;

class Player {
public:
    Player();

    // Figure management
    void addFigure(Figure* newFigure);
    void removeFigure(string position);
    vector<Figure*> getFigureVector();
    Figure* getFigureAtLocationX(string location);

    // King & check
    string getKingLocation();
    void setCheckState(bool check);
    bool isCheckedState() const;

    // Turn handling
    bool isPlayerTurn();
    void changeTurnState();

    // Movement / logic
    bool isOneOfMyFiguresAtXLocation(string location);
    bool destinationPosOfFigureIsMyFigure(string destinationPos);
    bool moveFigure(string sourcePosOfFigure, string destinationPosOfFigure);
    bool isOneOfMyFiguresCanReachLocation(string location);
    bool isLegitEatingMoveForPawn(string source, string destination, string name);

    // Debug / board string
    string getPlayerString();

private:
    vector<Figure*> figures;
    bool thisPlayerTurn;
    bool isChecked;
};
