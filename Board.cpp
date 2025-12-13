#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{
    board = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0";
}

/* ---------------- TURN HANDLING ---------------- */

bool Board::isWhiteTurn() const
{
    return board[64] == '0';
}

bool Board::isBlackTurn() const
{
    return board[64] == '1';
}

void Board::changeTurn()
{
    board[64] = (board[64] == '0') ? '1' : '0';
}

/* ---------------- BOARD ACCESS ---------------- */

string Board::getBoard() const
{
    return board;
}

void Board::setBoard(string newBoard)
{
    if (newBoard.size() == 65)
        board = newBoard;
}

void Board::printBoard() const
{
    cout << "\n  +-----------------+\n";
    for (int row = 0; row < 8; row++)
    {
        cout << (8 - row) << " | ";
        for (int col = 0; col < 8; col++)
            cout << board[row * 8 + col] << ' ';
        cout << "|\n";
    }
    cout << "  +-----------------+\n    a b c d e f g h\n";
}

/* ---------------- FIGURE ACTIONS ---------------- */

void Board::eatFigure(string position)
{
    int col = position[0] - 'a';
    int row = 8 - (position[1] - '0');
    board[row * 8 + col] = '#';
}

/* ---------------- BOARD LOGIC ---------------- */

bool Board::isSquareTaken(string position) const
{
    int col = position[0] - 'a';
    int row = 8 - (position[1] - '0');
    return board[row * 8 + col] != '#';
}

bool Board::isThereInterupterFigureAtPath(string source, string destination) const
{
    int srcCol = source[0] - 'a';
    int srcRow = 8 - (source[1] - '0');
    int dstCol = destination[0] - 'a';
    int dstRow = 8 - (destination[1] - '0');

    int dCol = dstCol - srcCol;
    int dRow = dstRow - srcRow;

    // Knight skips path
    if ((abs(dCol) == 1 && abs(dRow) == 2) ||
        (abs(dCol) == 2 && abs(dRow) == 1))
        return false;

    int stepCol = (dCol == 0 ? 0 : (dCol > 0 ? 1 : -1));
    int stepRow = (dRow == 0 ? 0 : (dRow > 0 ? 1 : -1));

    int col = srcCol + stepCol;
    int row = srcRow + stepRow;

    while (col != dstCol || row != dstRow)
    {
        if (board[row * 8 + col] != '#')
            return true;

        col += stepCol;
        row += stepRow;
    }

    return false;
}

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
        return false;

    if (isThereInterupterFigureAtPath(source, destination))
        return false;

    board[dstIndex] = piece;
    board[srcIndex] = '#';

    changeTurn();
    return true;
}

/* ---------------- KING CHECK LOGIC ---------------- */

bool Board::isKingChecked() const
{
    return false; // stage C
}


bool Board::isOneOfBlackFiguresCanReachLocationX(string source, string destination) const {
    // Placeholder
    return false;
}

bool Board::isOneOfWhiteFiguresCanReachLocationX(string source, string destination) const {
    // Placeholder
    return false;
}
