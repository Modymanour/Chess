#pragma once
#include <vector>
#include <string>
#include <utility>
#include "piece.h"
#include "boardcell.h"
#include "whitePieces.h"
#include "blackpieces.h"

class WhitePieces;
class BlackPieces;
class Piece;
//This class is going to be a singleton

class Board {
private:
    static Board* instance;
    Board();
public:
    bool isWhiteTurn;
    std::vector<std::vector<Boardcell>> boardCells;
    std::vector<Piece*> pieces;
    WhitePieces* whitePieces;
    BlackPieces* blackPieces;
    static Board* getInstance();
    void initializeBoard();
    void displayBoard();
    void displayPieces();
    void updateBoard();
    void updatePossibleMoves();
    bool movePiece(std::pair<std::string, int> startPos, std::pair<std::string, int> endPos);
    
    // Pin detection and validation methods
    bool isKingInCheck(bool isWhiteKing, const std::vector<std::vector<Boardcell>>& board);
    bool isPiecePinned(Piece* piece, const std::vector<std::vector<Boardcell>>& board);
    std::pair<std::string, int> getPinDirection(Piece* piece, const std::vector<std::vector<Boardcell>>& board);
    Piece* findKing(bool isWhite, const std::vector<std::vector<Boardcell>>& board);
    std::vector<std::pair<std::string, int>> filterMovesForPin(Piece* piece, const std::vector<std::pair<std::string, int>>& moves, const std::vector<std::vector<Boardcell>>& board);
    std::vector<std::pair<std::string,int>> kingCheckPath(const std::vector<std::vector<Boardcell>>& board);
    std::vector<std::pair<std::string, int>> filterMovesForCheck(Piece* piece, const std::vector<std::pair<std::string, int>>& moves, const std::vector<std::vector<Boardcell>>& board);
    bool wouldMoveExposeKing(Piece* piece, const std::pair<std::string, int>& movePos, const std::vector<std::vector<Boardcell>>& board);
    bool isCheckmate(bool isWhiteKing, const std::vector<std::vector<Boardcell>>& board);
    
    ~Board();
};
