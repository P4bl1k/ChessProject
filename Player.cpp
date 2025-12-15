#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

/*
This function; is the constructor for the Player class, it initializes the player with a pointer to the board ->
-> sets the turn state to false and the check state to false.
input: board - pointer to the game board.
output: None.
*/
Player::Player(Board* board)
{
    this->board = board;
    thisPlayerTurn = false;
    isChecked = false;
}

/*
This function; is the destructor for the Player class, it deletes all dynamically allocated figures owned by the player.
input: None.
output: None.
*/
Player::~Player()
{
    for (Figure* f : figures)
    {
        delete f;
    }
}

/*
This function; adds a new figure to the player's figure list.
input: newFigure - pointer to the figure to add.
output: None.
*/
void Player::addFigure(Figure* newFigure)
{
    figures.push_back(newFigure);
}

/*
This function; removes a figure from the player by its board position.
input: position - position of the figure in chess notation.
output: None.
*/
void Player::removeFigure(string position)
{
    for (int i = 0; i < figures.size(); i++)
    {
        if (figures[i]->getPosition() == position)
        {
            delete figures[i];
            figures.erase(figures.begin() + i);
            return;
        }
    }
}

/*
This function; returns the vector containing all the player's figures.
input: None.
output: figures - a vector of pointers to Figure objects.
*/
vector<Figure*> Player::getFigureVector()
{
    return figures;
}

/*
This function; returns the figure located at a given position.
input: location - board position in chess notation
output: f / ... - pointer to the figure if found, nullptr otherwise.
*/
Figure* Player::getFigureAtLocationX(string location)
{
    for (Figure* f : figures)
    {
        if (f->getPosition() == location)
        {
            return f;
        }
    }
    return nullptr;
}

/*
This function; returns the current location of the player's king.
input: None.
output: ... - position of the king as a string, or empty string if not found.
*/
string Player::getKingLocation()
{
    for (Figure* f : figures)
    {
        if (f->getType() == "King")
        {
            return f->getPosition();
        }
    }
    return "";
}

/*
This function; sets the player's check state.
input: check: True - if the player is in check, False - otherwise.
output: None.
*/
void Player::setCheckState(bool check)
{
    isChecked = check;
}

/*
This function; checks whether the player is currently in check.
input: None.
output: isChecked: True - if the player is in check, False - otherwise.
*/
bool Player::isCheckedState() const
{
    return isChecked;
}

/*
This function checks whether it is currently this player's turn.
input: None.
output: thisPlayerTurn: True - if it is the player's turn, False - otherwise.
*/
bool Player::isPlayerTurn()
{
    return thisPlayerTurn;
}

/*
This function switches the player's turn state.
input: None.
output: None.
*/
void Player::changeTurnState()
{
    thisPlayerTurn = !thisPlayerTurn;
}

/*
This function checks if one of the player's figures is located at the given position.
input: location - board position in chess notation.
output: True - if a figure exists at the location, False - otherwise.
*/
bool Player::isOneOfMyFiguresAtXLocation(string location)
{
    return getFigureAtLocationX(location) != nullptr;
}

/*
This function checks if the destination position contains one of the player's own figures.
input: destinationPos - destination board position.
output: True if the destination contains the player's figure.
*/
bool Player::destinationPosOfFigureIsMyFigure(string destinationPos)
{
    return isOneOfMyFiguresAtXLocation(destinationPos);
}

/*
This function moves one of the player's figures from source to destination, it validates the move using the figure and the board.
input: source - starting position, destination - target position.
output: True - if the move was successful, False - otherwise.
*/
bool Player::moveFigure(string source, string destination)
{
    Figure* fig = getFigureAtLocationX(source);
    if (!fig)
    {
        return false;
    }
    if (!fig->isLegitMove(destination))
    {
        return false;
    }
    if (!board->moveFigureAtBoard(source, destination)) //BOARD executes the move (including en passant).
    {
        return false;
    }
    fig->move(destination);
    return true;
}

/*
This function checks if any of the player's figures can reach the given location.
input: location - target board position.
output: True - if at least one figure can reach the location, False - otherwise.
*/
bool Player::isOneOfMyFiguresCanReachLocation(const string location)
{
    for (Figure* f : figures)
    {
        if (f->isLegitMove(location))
        {
            return true;
        }
    }
    return false;
}

/*
This function returns a string representation of the player's figures.
input: None.
output: result - a string describing all the player's figures.
*/
string Player::getPlayerString()
{
    string result = "";
    for (Figure* f : figures)
    {
        result += f->getType() + "@" + f->getPosition() + " ";
    }
    return result;
}
