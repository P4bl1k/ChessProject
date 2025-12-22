#include "Board.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
This function; is a constructor that initializes the chess board with pieces in their starting positions.
Input: None.
Output: None.
*/
Board::Board()
{
    this->blackSide = *(new Player());
    this->whiteSide = *(new Player());
    this->board = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0";

	this->whiteSide.changeTurnState(); //Which side starts (white).

    this->blackSide.addFigure(new Rook("r", "Rook", "a8")); //Add the rooks.
    this->blackSide.addFigure(new Rook("r", "Rook", "h8"));
    this->whiteSide.addFigure(new Rook("R", "Rook", "a1"));
    this->whiteSide.addFigure(new Rook("R", "Rook", "h1"));
	this->blackSide.addFigure(new Knight("k", "Knight", "b8")); //Add the knights.
    this->blackSide.addFigure(new Knight("k", "Knight", "g8"));
    this->whiteSide.addFigure(new Knight("K", "Knight", "b1"));
    this->whiteSide.addFigure(new Knight("K", "Knight", "g1"));
	this->blackSide.addFigure(new Queen("q", "Queen", "d8")); //Add the queens.
    this->whiteSide.addFigure(new Queen("Q", "Queen", "d1"));
	this->blackSide.addFigure(new Bishop("b", "Bishop", "c8")); //Add the bishops.
    this->blackSide.addFigure(new Bishop("b", "Bishop", "f8"));
    this->whiteSide.addFigure(new Bishop("B", "Bishop", "c1"));
    this->whiteSide.addFigure(new Bishop("B", "Bishop", "f1"));
	this->blackSide.addFigure(new King("k", "King", "e8")); //Add the kings.
    this->whiteSide.addFigure(new King("K", "King", "e1"));
    const std::string blackPawnPositions[] = { "a7","b7","c7","d7","e7","f7","g7","h7" }; //Add pawns.
    const std::string whitePawnPositions[] = { "a2","b2","c2","d2","e2","f2","g2","h2" };
    for (int i = 0; i < 8; i++)
    {
        this->blackSide.addFigure(new Pawn("p", "Pawn", blackPawnPositions[i]));
        this->whiteSide.addFigure(new Pawn("P", "Pawn", whitePawnPositions[i]));
    }
}

/*
This function; checks if it is white's turn to play.
Input: None.
Output: true  - if it is white's turn, false - otherwise.
*/
bool Board::isWhiteTurn() const
{
    return this->whiteSide.isPlayerTurn();
}

/*
This function; checks if it is black turn to play.
Input: None.
Output: true - if it is black's turn, false - otherwise.
*/
bool Board::isBlackTurn() const
{
    return this->blackSide.isPlayerTurn();
}

/*
This function; returns the current board state as a string.
Input: None.
Output: board - string board representation.
*/
std::string Board::getBoardString() const
{
    return this->board;
}

/*
This function; prints the current board to the console.
Input: None.
Output: None.
*/
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

/*
This function; removes an opponent piece from the given board position.
Input: position - board position.
Output: None.
*/
void Board::eatPiece(const std::string position)
{
    if (isWhiteTurn())
    {
        if (this->blackSide.isOneOfMyFiguresAtXLocation(position))
        {
            this->blackSide.removeFigure(position);
        }
    }
    else
    {
        if (this->whiteSide.isOneOfMyFiguresAtXLocation(position))
        {
            this->whiteSide.removeFigure(position);
        }
    }
}

/*
This function; checks if a board square is occupied.
Input: position - board position.
Output: true - if the square is occupied, false - otherwise.
*/
bool Board::isSquareTaken(const std::string position) const
{
    return blackSide.isOneOfMyFiguresAtXLocation(position) || whiteSide.isOneOfMyFiguresAtXLocation(position);
}

/*
This function; moves a piece from a source to a destination while validating legality.
Input: source - starting square, destination - target square.
Output: resString - move status code.
*/
string Board::movePieceAtBoard(const string source, const string destination)
{
    string retString = "";
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
                if (source[0] == destination[0]) //Straight file move into any occupied square is illegal.
                {
                    if (isSquareTaken(destination))
                    {
                        return to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
                    }
                }
                else
                {
                    if (!blackSide.isOneOfMyFiguresAtXLocation(destination)) //Diagonal move must capture an opponent piece (no en-passant).
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
            Figure* tempFigure = blackSide.getFigureAtLocationX(destination); //If the eating isn't preventing check i will remake the piece.
            string name, type, position;
            name = tempFigure->getName();
            type = tempFigure->getType();
            position = tempFigure->getPosition();
            eatPiece(destination);
            if (isKingChecked())
            {
				whiteSide.getFigureAtLocationX(destination)->setPosition(source); //Forcing pawn back.
				blackSide.addFigure(createFigure(name, type, position)); //Adding the piece back.
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
        if (whiteSide.isOneOfMyFiguresAtXLocation(source)) //Black side's moving code. same as white.
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
                if (source[0] == destination[0]) //Straight file move into any occupied square is illegal.
                {
                    if (isSquareTaken(destination))
                    {
                        return to_string(ILLEGALMOVEILLEGALMOVEMENTOFPIECE);
                    }
                }
                else
                {
                    if (!whiteSide.isOneOfMyFiguresAtXLocation(destination)) //Diagonal move must capture an opponent piece (no en-passant).
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
            Figure* tempFigure = whiteSide.getFigureAtLocationX(destination); //If the eating isn't preventing check i will remake the piece.
            string name, type, position;
            name = tempFigure->getName();
            type = tempFigure->getType();
            position = tempFigure->getPosition();

            eatPiece(destination);

            if (isKingChecked())
            {
				blackSide.getFigureAtLocationX(destination)->setPosition(source); //Forcing pawn back.
				whiteSide.addFigure(createFigure(name, type, position)); //Adding the piece back.
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
	if (retString == "0" || retString == "1" || retString == "8") //If the move was legal.
    {
        changeTurn(); //Changes turn.
    }
    return retString;
}

/*
This function; updates the board string to reflect current piece positions.
Input: None.
Output: None.
*/
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
        {
            newBoardStr[i] = wf->getName()[0];
        }
        else if (bf)
        {
            newBoardStr[i] = bf->getName()[0];
        }
        else
        {
            newBoardStr[i] = '#';
        }
    }
    setBoardString(newBoardStr);
}

/*
This function; sets the board string to a new value.
Input: newBoard - updated board state.
Output: None.
*/
void Board::setBoardString(const std::string newBoard)
{
    this->board = newBoard;
}

/*
This function; switches the turn between white and black players.
Input: None.
Output: None.
*/
void Board::changeTurn()
{
    this->blackSide.changeTurnState();
    this->whiteSide.changeTurnState();
}

/*
This function; checks if the current player's king is in check.
Input: None.
Output: true - if the king is in check, false - otherwise.
*/
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

/*
This function; creates a chess piece object based on type and position.
Input: name - piece name, type - piece type, position - board position.
Output: Figure* - pointer to the created piece.
*/
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

/*
This function; checks if any black piece can legally reach a destination square.
Input: srcPosition - start square, destPosition - target square.
Output: true - if reachable, false - otherwise.
*/
bool Board::isOneOfBlackPiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const
{
    return blackSide.isOneOfMyFiguresCanReachLocation(destPosition) && !isThereAnInterrupterPieceAtPath(srcPosition, destPosition);
}

/*
This function; checks if any white piece can legally reach a destination square.
Input: srcPosition - start square, destPosition - target square.
Output: true - if reachable, false - otherwise.
*/
bool Board::isOneOfWhitePiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const
{
    return whiteSide.isOneOfMyFiguresCanReachLocation(destPosition) && !isThereAnInterrupterPieceAtPath(srcPosition, destPosition);
}

/*
This function; checks if any piece blocks the path between two squares.
Input: srcPosition - start square, destPosition - target square.
Output: true - if a piece blocks the path, false - otherwise.
*/
bool Board::isThereAnInterrupterPieceAtPath(std::string srcPosition, std::string destPosition) const
{
    int srcCol = srcPosition[0] - 'a'; //Step from src to dest and check squares (excluding src and dest).
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
