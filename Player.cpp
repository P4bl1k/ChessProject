#include "Player.h"

/* ---------------- CONSTRUCTOR ---------------- */

Player::Player() {
    thisPlayerTurn = false;
    isChecked = false;
}

/* ---------------- FIGURE MANAGEMENT ---------------- */

void Player::addFigure(Figure* newFigure) {
    figures.push_back(newFigure);
}

void Player::removeFigure(string position) {
    for (int i = 0; i < figures.size(); i++) {
        if (figures[i]->getPosition() == position) {
            delete figures[i];
            figures.erase(figures.begin() + i);
            return;
        }
    }
}

vector<Figure*> Player::getFigureVector() {
    return figures;
}

Figure* Player::getFigureAtLocationX(string location) {
    for (Figure* f : figures) {
        if (f->getPosition() == location)
            return f;
    }
    return nullptr;
}

/* ---------------- KING & CHECK ---------------- */

string Player::getKingLocation() {
    for (Figure* f : figures) {
        if (f->getName() == "King")
            return f->getPosition();
    }
    return "";
}

void Player::setCheckState(bool check) {
    isChecked = check;
}

bool Player::isCheckedState() const {
    return isChecked;
}

/* ---------------- TURN HANDLING ---------------- */

bool Player::isPlayerTurn() {
    return thisPlayerTurn;
}

void Player::changeTurnState() {
    thisPlayerTurn = !thisPlayerTurn;
}

/* ---------------- MOVEMENT LOGIC ---------------- */

bool Player::isOneOfMyFiguresAtXLocation(string location) {
    return getFigureAtLocationX(location) != nullptr;
}

bool Player::destinationPosOfFigureIsMyFigure(string destinationPos) {
    return isOneOfMyFiguresAtXLocation(destinationPos);
}

bool Player::moveFigure(string sourcePosOfFigure, string destinationPosOfFigure) {
    Figure* fig = getFigureAtLocationX(sourcePosOfFigure);
    if (!fig)
        return false;

    if (!fig->canReach(destinationPosOfFigure))
        return false;

    fig->setPosition(destinationPosOfFigure);
    return true;
}

bool Player::isOneOfMyFiguresCanReachLocation(string location) {
    for (Figure* f : figures) {
        if (f->canReach(location))
            return true;
    }
    return false;
}

/* ---------------- PAWN SPECIAL LOGIC ---------------- */

bool Player::isLegitEatingMoveForPawn(string source, string destination, string name) {
    if (name != "Pawn")
        return false;

    int srcCol = source[0] - 'a';
    int srcRow = source[1] - '0';
    int dstCol = destination[0] - 'a';
    int dstRow = destination[1] - '0';

    // Pawn eats diagonally (1 step)
    if (abs(srcCol - dstCol) == 1 && abs(srcRow - dstRow) == 1)
        return true;

    return false;
}

/* ---------------- STRING REPRESENTATION ---------------- */

string Player::getPlayerString() {
    string result;
    for (Figure* f : figures) {
        result += f->getName() + "@" + f->getPosition() + " ";
    }
    return result;
}
