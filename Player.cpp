#include "Player.h"
#include "Board.h"

#include <string>
#include <vector>

using namespace std;

/*
Constructor – initializes player with a board pointer,
sets turn state to false and check state to false.
*/
Player::Player()
{
    this->thisPlayerTurn = false;
    this->isChecked = false;
    this->board = nullptr;
}

/*
Adds a figure to the player's list.
*/
void Player::addFigure(Figure* newFigure)
{
    this->figures.push_back(newFigure);
}

/*
Removes a figure by its board position.
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
Returns the vector of the player's figures.
*/
vector<Figure*> Player::getFigureVector()
{
    return this->figures;
}

/*
Returns the figure located at a specific position.
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
    return nullptr; // fix: explicit nullptr when not found
}

/*
This function changes the turn state of the player.
*/
void Player::changeTurnState()
{
    this->thisPlayerTurn = !this->thisPlayerTurn;
}

/*
Returns true if it is the player's turn.
*/
bool Player::isPlayerTurn() const
{
    return this->thisPlayerTurn;
}

string Player::getKingLocation() const
{
    for (int i = 0; i < this->figures.size(); i++)
    {
        if (this->figures[i] != nullptr && this->figures[i]->getType() == "King")
        {
            return this->figures[i]->getPosition();
        }
    }
    return ""; // fix: explicit empty string when not found
}
/*
this function returns if one of this side pieces is at given location.
input: location to search a piece on.
output: true or false.
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
operator =
*/
Player Player::operator=(Player& otherPlayer)
{
    this->figures = otherPlayer.getFigureVector();
    this->thisPlayerTurn = otherPlayer.isPlayerTurn();
    return *this;
}

/*
Sets check state.
*/
void Player::setCheckState(bool check)
{
    isChecked = check;
}

/*
Returns check state.
*/
bool Player::isCheckedState() const
{
    return isChecked;
}

/*
Checks if destination contains player's figure.
*/
bool Player::destinationPosOfFigureIsMyFigure(string destinationPos)
{
    return isOneOfMyFiguresAtXLocation(destinationPos);
}

/*
Moves a figure from source to destination.
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
Checks if any figure can reach the given location.
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
Returns a string describing all player's figures.
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
this function checks if a pawn can eat from source to destination.
input: dource and destination locations to check and name of piece
output: true or false.
*/
bool Player::isLegitEatingMoveForPawn(const string source, const string destination, const string name)
{
    bool diagonalOnce = false;

    //black can eat 1 diagonal forward which is backward for white
    if (name == "P")
    {
        diagonalOnce = source[1] - destination[1] == -1 && std::abs(source[0] - destination[0]) == 1;
    }
    else
    {
        diagonalOnce = source[1] - destination[1] == 1 && std::abs(source[0] - destination[0]) == 1;
    }

    return diagonalOnce;
}