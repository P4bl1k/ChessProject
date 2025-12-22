#include "Player.h"
#include "Board.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Knight.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
This function; constructs a Player with default values for turn, check state, and board pointer.
Input: None.
Output: None.
*/
Player::Player()
{
    this->thisPlayerTurn = false;
    this->isChecked = false;
    this->board = nullptr;
}

/*
This function; adds a chess piece to the player's collection.
Input: newFigure - pointer to the piece.
Output: None.
*/
void Player::addFigure(Figure* newFigure)
{
    this->figures.push_back(newFigure);
}

/*
This function; removes a figure from the player at the given position.
Input: position - figure location.
Output: None.
*/
void Player::removeFigure(string position)
{
    for (size_t i = 0; i < this->figures.size(); ++i)
    {
        Figure* currFigure = this->figures[i];
        if (currFigure != nullptr && currFigure->getPosition() == position)
        {
            this->figures.erase(this->figures.begin() + i);
            break;
        }
    }
}

/*
This function; returns the player's list of figures.
Input: None.
Output: vector<Figure*> - figures collection.
*/
vector<Figure*> Player::getFigureVector()
{
    return this->figures;
}

/*
This function; returns the figure located at a specific board position.
Input: location - board position.
Output: Figure* - pointer to figure or nullptr.
*/
Figure* Player::getFigureAtLocationX(const string location) const
{
    for (int i = 0; i < this->figures.size(); i++)
    {
        if (this->figures[i] != nullptr && this->figures[i]->getPosition() == location)
        {
            return this->figures[i];
        }
    }
    return nullptr; //Explicit nullptr when not found.
}

/*
This function; toggles the player's turn state.
Input: None.
Output: None.
*/
void Player::changeTurnState()
{
    this->thisPlayerTurn = !this->thisPlayerTurn;
}

/*
This function; checks if it is this player's turn.
Input: None.
Output: thisPlayerTurn: true - if it is, false - otherwise.
*/
bool Player::isPlayerTurn() const
{
    return this->thisPlayerTurn;
}

/*
This function; returns the current position of the player's King.
Input: None.
Output: ... - king position.
*/
string Player::getKingLocation() const
{
    for (int i = 0; i < this->figures.size(); i++)
    {
        if (this->figures[i] != nullptr && this->figures[i]->getType() == "King")
        {
            return this->figures[i]->getPosition();
        }
    }
    return ""; //Explicit empty string when not found.
}

/*
This function; checks if the player has a figure at a given position.
Input: location - board position.
Output: true - if a figure stands there, false - otherwise.
*/
bool Player::isOneOfMyFiguresAtXLocation(const string location) const
{
    for (int i = 0; i < this->figures.size(); i++)
    {
        if (this->figures[i] != nullptr && this->figures[i]->getPosition() == location)
        {
            return true;
        }
    }
    return false;
}

/*
This function; assigns another player's state to this player.
Input: otherPlayer - source player.
Output: ... - assigned player object.
*/
Player Player::operator=(Player& otherPlayer)
{
    this->figures = otherPlayer.getFigureVector();
    this->thisPlayerTurn = otherPlayer.isPlayerTurn();
    return *this;
}

/*
This function; sets the player's check state.
Input: check - check status.
Output: None.
*/
void Player::setCheckState(bool check)
{
    isChecked = check;
}

/*
This function; checks if the player is currently in check.
Input: None.
Output: isChecked: true - if in checked state, false - otherwise.
*/
bool Player::isCheckedState() const
{
    return isChecked;
}

/*
This function; checks if a destination position is occupied by the player's own figure.
Input: destinationPos - target square.
Output: ...: true - if occupied by the player's own figure, false - otherwise.
*/
bool Player::destinationPosOfFigureIsMyFigure(string destinationPos)
{
    return isOneOfMyFiguresAtXLocation(destinationPos);
}

/*
This function; moves a player's figure from source to destination if the move is legal.
Input: sourcePosOfPiece - starting square, destinationPosOfPiece - target square.
Output: returnString - move result code.
*/
string Player::moveFigure(const string sourcePosOfPiece, const string destinationPosOfPiece)
{
    string returnString = to_string(ILLEGALMOVENOORIGINALPIECE);

    if (isOneOfMyFiguresAtXLocation(destinationPosOfPiece))
    {
        return to_string(ILLEGALMOVETHEREISALLY);
    }

    if (isOneOfMyFiguresAtXLocation(sourcePosOfPiece))
    {
        Figure* FigureAtXLocation = getFigureAtLocationX(sourcePosOfPiece);
        if (FigureAtXLocation != nullptr)
        {
            returnString = FigureAtXLocation->move(destinationPosOfPiece);
        }
    }

    return returnString;
}

/*
This function; checks if any of the player's figures can legally reach a given location.
Input: location - target square.
Output: true - if reachable, false - otherwise.
*/
bool Player::isOneOfMyFiguresCanReachLocation(const string location) const
{
    for (int i = 0; i < this->figures.size(); i++)
    {
        string oldPos = this->figures[i]->getPosition();

        if (this->figures[i]->isLegitMove(location))
        {
            return true;
        }
    }
    return false;
}

/*
This function; returns a string representation of all the player's figures and their positions.
Input: None.
Output: result - figures and positions.
*/
string Player::getPlayerString()
{
    string result = "";
    for (Figure* f : figures)
    {
        if (f != nullptr)
            result += f->getType() + "@" + f->getPosition() + " ";
    }
    return result;
}

/*
This function; checks if a pawn's capture move from source to destination is legal.
Input: source - start square, destination - target square, name - pawn name.
Output: true - if the capture is legal, false - otherwise.
*/
bool Player::isLegitEatingMoveForPawn(const string source, const string destination, const string name)
{
    bool diagonalOnce = false;

    if (name == "P") //Black can eat 1 diagonal forward which is backward for white.
    {
        diagonalOnce = source[1] - destination[1] == -1 && std::abs(source[0] - destination[0]) == 1;
    }
    else
    {
        diagonalOnce = source[1] - destination[1] == 1 && std::abs(source[0] - destination[0]) == 1;
    }

    return diagonalOnce;
}
