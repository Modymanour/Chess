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
//This class is going to be a singleton

class Board {
private:
    static Board* instance;
    Board();
public:
    bool isWhiteTurn;
    std::vector<std::vector<Boardcell>> boardCells;
    WhitePieces* whitePieces;
    BlackPieces* blackPieces;
    static Board* getInstance();
    void initializeBoard();
    void displayBoard();
    void updateBoard();
    void updatePossibleMoves();
    bool movePiece(std::pair<std::string, int> startPos, std::pair<std::string, int> endPos);
    ~Board();
};