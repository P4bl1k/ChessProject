#include "Board.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
This function; is the constructor for the board class.
input: None.
output: None.
*/
Board::Board()
{
    board = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0";
}

/*
This function; checks if it's white's turn.
input: None.
output: True - if it's white's turn, False - otherwise.
*/
bool Board::isWhiteTurn() const
{
    return board[64] == '0';
}

/*
This function; check if it's black's turn.
input: None.
output: True - if it's black's turn, False - otherwise.
*/
bool Board::isBlackTurn() const
{
    return board[64] == '1';
}

/*
This function; switches the turn between white and black, If it is white's turn, it becomes black's turn and opposite.
input: None.
output: None.
*/
void Board::changeTurn()
{
    board[64] = (board[64] == '0') ? '1' : '0';
}

/*
This function; returns the current board representation as a string.
input: None.
output: board - a string representing the board and current turn.
*/
string Board::getBoard() const
{
    return board;
}

/*
This function; sets the board to a new board state, it must be must be exactly 65 characters long.
input: newBoard - a string representing the new board.
output: None.
*/
void Board::setBoard(string newBoard)
{
    if (newBoard.size() == 65)
    {
        board = newBoard;
    }
}

/*
This function; prints the chess board.
input: None.
output: None.
*/
void Board::printBoard() const
{
    cout << "\n  +-----------------+\n";
    for (int row = 0; row < 8; row++)
    {
        cout << (8 - row) << " | ";
        for (int col = 0; col < 8; col++)
        {
            cout << board[row * 8 + col] << ' ';
        }
        cout << "|\n";
    }
    cout << "  +-----------------+\n    a b c d e f g h\n";
}

/*
This function; removes a figure from the board at the given position.
input: position - a string representing the board position.
output: None.
*/
void Board::eatFigure(string position)
{
    int col = position[0] - 'a';
    int row = 8 - (position[1] - '0');
    board[row * 8 + col] = '#';
}

/*
This function checks whether a square on the board is occupied.
input: position - a string representing the board position.
output: True - if the square is taken, False - otherwise.
*/
bool Board::isSquareTaken(string position) const
{
    int col = position[0] - 'a';
    int row = 8 - (position[1] - '0');
    return board[row * 8 + col] != '#';
}

/*
This function; checks if there is any figure blocking the path -> ***Check documentation for mistakes...
-> between a source and destination square, knights are excluded since they can jump over other pieces.
input: source - starting position in chess notation, destination - target position in chess notation.
output: True - if there is a blocking figure, False - otherwise.
*/
bool Board::isThereInterupterFigureAtPath(string source, string destination) const
{
    int srcCol = source[0] - 'a';
    int srcRow = 8 - (source[1] - '0');
    int dstCol = destination[0] - 'a';
    int dstRow = 8 - (destination[1] - '0');
    int dCol = dstCol - srcCol;
    int dRow = dstRow - srcRow;
    if ((abs(dCol) == 1 && abs(dRow) == 2) || (abs(dCol) == 2 && abs(dRow) == 1)) //Knight skips path.
    {
        return false;
    }
    int stepCol = (dCol == 0 ? 0 : (dCol > 0 ? 1 : -1));
    int stepRow = (dRow == 0 ? 0 : (dRow > 0 ? 1 : -1));
    int col = srcCol + stepCol;
    int row = srcRow + stepRow;
    while (col != dstCol || row != dstRow)
    {
        if (board[row * 8 + col] != '#')
        {
            return true;
        }
        col += stepCol;
        row += stepRow;
    }
    return false;
}

/*
This function moves a figure from a source square to a destination square -> ***Check documentation for mistakes...
-> It checks if the move is valid regarding path blocking and source validity.
input: source - starting position in chess notation, destination - target position in chess notation.
output: True - if the move was successful, False - otherwise.
*/
bool Board::moveFigureAtBoard(string source, string destination)
{
    int srcCol = source[0] - 'a';
    int srcRow = 8 - (source[1] - '0');
    int dstCol = destination[0] - 'a';
    int dstRow = 8 - (destination[1] - '0');
    int srcIndex = srcRow * 8 + srcCol;
    int dstIndex = dstRow * 8 + dstCol;
    char piece = board[srcIndex];
    if (piece == '#')
    {
        return false;
    }
    if (isThereInterupterFigureAtPath(source, destination))
    {
        return false;
    }
    board[dstIndex] = piece;
    board[srcIndex] = '#';
    changeTurn();
    return true;
}

/*
This function; checks whether the king is currently in check. ***Placeholder... ***Check documentation for mistakes...
input: None.
output: ???
*/
bool Board::isKingChecked() const
{
    //Placeholder.
	return false; //Stage C.
}

/*
This function; returns an updated board string. ***Placeholder... ***Check documentation for mistakes...
input: None
output: The current board string.
*/
string Board::updatedBoardString() const //TODO...
{
    //Placeholder.
    return board;
}

/*
This function; creates a figure on the board. ***Placeholder... ***Check documentation for mistakes...
input: name - name of the figure, type - type of the figure, position - position in chess.
output: None
*/
void Board::createFigure(string name, string type, string position) //TODO...
{
    //Placeholder.
}

/*
This function; checks if any black figure can reach a given location. ***Placeholder... ***Check documentation for mistakes...
input: source - starting position, destination - target position.
output: ???
*/
bool Board::isOneOfBlackFiguresCanReachLocationX(string source, string destination) const
{
    //Placeholder.
    return false;
}

/*
This function checks if any white figure can reach a given location. ***Placeholder... ***Check documentation for mistakes...
input: source - starting position, destination - target position.
output: ???
*/
bool Board::isOneOfWhiteFiguresCanReachLocationX(string source, string destination) const
{
    //Placeholder.
    return false;
}
