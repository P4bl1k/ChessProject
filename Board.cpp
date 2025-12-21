#include "Board.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Constructor of Board.
It initializes black and white sides, sets up the board string, adds all pieces and determines the starting turn.
*/
Board::Board()
{
    this->blackSide = *(new Player());
    this->whiteSide = *(new Player());
    this->board = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0";

    // Which side starts (white)
    this->whiteSide.changeTurnState();

    // Add rooks
    this->blackSide.addFigure(new Rook("r", "Rook", "a8"));
    this->blackSide.addFigure(new Rook("r", "Rook", "h8"));
    this->whiteSide.addFigure(new Rook("R", "Rook", "a1"));
    this->whiteSide.addFigure(new Rook("R", "Rook", "h1"));

    // Add knights
    this->blackSide.addFigure(new Knight("k", "Knight", "b8"));
    this->blackSide.addFigure(new Knight("k", "Knight", "g8"));
    this->whiteSide.addFigure(new Knight("K", "Knight", "b1"));
    this->whiteSide.addFigure(new Knight("K", "Knight", "g1"));

    // Add queens
    this->blackSide.addFigure(new Queen("q", "Queen", "d8"));
    this->whiteSide.addFigure(new Queen("Q", "Queen", "d1"));

    // Add bishops
    this->blackSide.addFigure(new Bishop("b", "Bishop", "c8"));
    this->blackSide.addFigure(new Bishop("b", "Bishop", "f8"));
    this->whiteSide.addFigure(new Bishop("B", "Bishop", "c1"));
    this->whiteSide.addFigure(new Bishop("B", "Bishop", "f1"));

    // Add kings
    this->blackSide.addFigure(new King("k", "King", "e8"));
    this->whiteSide.addFigure(new King("K", "King", "e1"));

    // Add pawns
    const std::string blackPawnPositions[] = { "a7","b7","c7","d7","e7","f7","g7","h7" };
    const std::string whitePawnPositions[] = { "a2","b2","c2","d2","e2","f2","g2","h2" };
    for (int i = 0; i < 8; i++)
    {
        this->blackSide.addFigure(new Pawn("p", "Pawn", blackPawnPositions[i]));
        this->whiteSide.addFigure(new Pawn("P", "Pawn", whitePawnPositions[i]));
    }
}

// Returns true if it is white's turn
bool Board::isWhiteTurn() const
{
    return this->whiteSide.isPlayerTurn();
}

// Returns true if it is black's turn
bool Board::isBlackTurn() const
{
    return this->blackSide.isPlayerTurn();
}

// Returns board as string
std::string Board::getBoardString() const
{
    return this->board;
}

// Prints the board (black at bottom)
void Board::printBoard() const
{
    for (int i = 63; i >= 0; i--)
    {
        std::cout << board[i] << " ";
        if (i % 8 == 0 && i != 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Removes a piece from a given position
void Board::eatPiece(const std::string position)
{
    if (isWhiteTurn())
    {
        if (this->blackSide.isOneOfMyFiguresAtXLocation(position))
            this->blackSide.removeFigure(position);
    }
    else
    {
        if (this->whiteSide.isOneOfMyFiguresAtXLocation(position))
            this->whiteSide.removeFigure(position);
    }
}

// Checks if square is occupied
bool Board::isSquareTaken(const std::string position) const
{
    return blackSide.isOneOfMyFiguresAtXLocation(position) || whiteSide.isOneOfMyFiguresAtXLocation(position);
}

// Moves a piece and returns frontend code
string Board::movePieceAtBoard(const string source, const string destination)
{
    string retString;

    if (isWhiteTurn())
    {
        if (blackSide.isOneOfMyFiguresAtXLocation(source))
        {
            return to_string(ILLEGALMOVENOORIGINALPIECE);
        }

        if (!whiteSide.isOneOfMyFiguresAtXLocation(source))
        {
            return to_string(ILLEGALMOVENOORIGINALPIECE);
        }
        if (!isOneOfWhitePiecesCanReachLocationX(source, destination) && whiteSide.getFigureAtLocationX(source)->getType() != "Knight")
        {
            return to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
        }
        {
            Figure* srcFig = whiteSide.getFigureAtLocationX(source);
            if (srcFig && srcFig->getName() == "P")
            {
                // straight file move into any occupied square is illegal
                if (source[0] == destination[0])
                {
                    if (isSquareTaken(destination))
                    {
                        return to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
                    }
                }
                else
                {
                    // diagonal move must capture an opponent piece (no en-passant)
                    if (!blackSide.isOneOfMyFiguresAtXLocation(destination))
                    {
                        return to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
                    }
                }
            }
        }
        bool flagForPawn = whiteSide.getFigureAtLocationX(source)->isLegitMove(destination);
        retString = whiteSide.moveFigure(source, destination);


        if (blackSide.isOneOfMyFiguresAtXLocation(destination) && retString == "0" && whiteSide.getFigureAtLocationX(destination)->getName() != "p")
        {
            //if the eating isn't preventing check i will remake the piece.
            Figure* tempFigure = blackSide.getFigureAtLocationX(destination);
            string name, type, position;
            name = tempFigure->getName();
            type = tempFigure->getType();
            position = tempFigure->getPosition();

            eatPiece(destination);

            if (isKingChecked())
            {
                //forcing pawn back
                whiteSide.getFigureAtLocationX(destination)->setPosition(source);
                //adding the piece back
                blackSide.addFigure(createFigure(name, type, position));
                retString = to_string(ILLEGALMOVESELFCHECK);
                return retString;
            }
        }

        if (isKingChecked() && retString == "0")
        {
            whiteSide.moveFigure(destination, source);
            retString = to_string(ILLEGALMOVESELFCHECK);
            return retString;
        }
    }
    else
    {
        //black side's moving code. same as white.

        if (whiteSide.isOneOfMyFiguresAtXLocation(source))
        {
            return to_string(ILLEGALMOVENOORIGINALPIECE);
        }

        if (!blackSide.isOneOfMyFiguresAtXLocation(source))
        {
            return to_string(ILLEGALMOVENOORIGINALPIECE);
        }

        if (!isOneOfBlackPiecesCanReachLocationX(source, destination) && blackSide.getFigureAtLocationX(source)->getType() != "Knight")
        {
            return to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
        }
        {
            Figure* srcFig = blackSide.getFigureAtLocationX(source);
            if (srcFig && srcFig->getName() == "p")
            {
                // straight file move into any occupied square is illegal
                if (source[0] == destination[0])
                {
                    if (isSquareTaken(destination))
                    {
                        return to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
                    }
                }
                else
                {
                    // diagonal move must capture an opponent piece (no en-passant)
                    if (!whiteSide.isOneOfMyFiguresAtXLocation(destination))
                    {
                        return to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
                    }
                }
            }
        }
        bool flagForPawn = blackSide.getFigureAtLocationX(source)->isLegitMove(destination);
        retString = blackSide.moveFigure(source, destination);


        if (whiteSide.isOneOfMyFiguresAtXLocation(destination) && retString == "0" && blackSide.getFigureAtLocationX(destination)->getName() != "P")
        {
            //if the eating isn't preventing check i will remake the piece.
            Figure* tempFigure = whiteSide.getFigureAtLocationX(destination);
            string name, type, position;
            name = tempFigure->getName();
            type = tempFigure->getType();
            position = tempFigure->getPosition();

            eatPiece(destination);

            if (isKingChecked())
            {
                //forcing pawn back
                blackSide.getFigureAtLocationX(destination)->setPosition(source);
                //adding the piece back
                whiteSide.addFigure(createFigure(name, type, position));
                retString = to_string(ILLEGALMOVESELFCHECK);
                return retString;
            }
        }

        if (isKingChecked() && retString == "0")
        {
            blackSide.moveFigure(destination, source);
            retString = to_string(ILLEGALMOVESELFCHECK);
            return retString;
        }

    }

    if (retString == "0" || retString == "1" || retString == "8")	//if move was legit.
    {
        changeTurn();	//changes turn
    }

    return retString;
}
// Updates board string from pieces
void Board::updateBoardString()
{
    std::string newBoardStr = this->board;

    for (int i = 0; i < 64; i++)
    {
        int col = i % 8;
        int row = 7 - (i / 8);
        char file = 'a' + col;
        char rank = '1' + row;
        std::string pos;
        pos.push_back(file);
        pos.push_back(rank);

        Figure* wf = whiteSide.getFigureAtLocationX(pos);
        Figure* bf = blackSide.getFigureAtLocationX(pos);

        if (wf)
            newBoardStr[i] = wf->getName()[0];
        else if (bf)
            newBoardStr[i] = bf->getName()[0];
        else
            newBoardStr[i] = '#';
    }

    setBoardString(newBoardStr);
}

// Sets board string
void Board::setBoardString(const std::string newBoard)
{
    this->board = newBoard;
}

// Changes turn between sides
void Board::changeTurn()
{
    this->blackSide.changeTurnState();
    this->whiteSide.changeTurnState();
}

// Checks if king is in check
bool Board::isKingChecked()
{
    if (isWhiteTurn())
    {
        if (blackSide.isOneOfMyFiguresCanReachLocation(whiteSide.getKingLocation()))
        {
            whiteSide.setCheckState(true);
            return true;
        }
        else
        {
            whiteSide.setCheckState(false);
        }
    }
    else
    {
        if (whiteSide.isOneOfMyFiguresCanReachLocation(blackSide.getKingLocation()))
        {
            blackSide.setCheckState(true);
            return true;
        }
        else
        {
            blackSide.setCheckState(false);
        }
    }
    return false;
}

Figure* Board::createFigure(const std::string name, const std::string type, const std::string position)
{
    if (type == "Rook") return new Rook(name, type, position);
    if (type == "Queen") return new Queen(name, type, position);
    if (type == "Bishop") return new Bishop(name, type, position);
    if (type == "Pawn") return new Pawn(name, type, position);
    if (type == "Knight") return new Knight(name, type, position);
    if (type == "King") return new King(name, type, position);
    return nullptr;
}

// Checks if black piece can reach destination
bool Board::isOneOfBlackPiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const
{
    return blackSide.isOneOfMyFiguresCanReachLocation(destPosition) && !isThereAnInterrupterPieceAtPath(srcPosition, destPosition);
}

// Checks if white piece can reach destination
bool Board::isOneOfWhitePiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const
{
    return whiteSide.isOneOfMyFiguresCanReachLocation(destPosition) && !isThereAnInterrupterPieceAtPath(srcPosition, destPosition);
}

// Checks if a path is blocked
bool Board::isThereAnInterrupterPieceAtPath(std::string srcPosition, std::string destPosition) const
{
    // Minimal implementation: step from src to dest and check squares (excluding src and dest)
    int srcCol = srcPosition[0] - 'a';
    int srcRow = srcPosition[1] - '1';
    int dstCol = destPosition[0] - 'a';
    int dstRow = destPosition[1] - '1';

    int dcol = (dstCol > srcCol) ? 1 : (dstCol < srcCol) ? -1 : 0;
    int drow = (dstRow > srcRow) ? 1 : (dstRow < srcRow) ? -1 : 0;

    int c = srcCol + dcol;
    int r = srcRow + drow;

    while (c != dstCol || r != dstRow)
    {
        std::string pos;
        pos.push_back('a' + c);
        pos.push_back('1' + r);
        if (isSquareTaken(pos))
            return true;
        c += dcol;
        r += drow;
    }

    return false;
}
