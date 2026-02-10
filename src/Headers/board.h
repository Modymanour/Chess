#pragma once
#include <vector>
#include <string>
#include <utility>
#include "piece.h"
#include "player.h"
#include "boardcell.h"
#include "whitePieces.h"
#include "blackpieces.h"

class WhitePieces;
class BlackPieces;
//This class is going to be a singleton

class Board {
public:
    bool isWhiteTurn;
    std::vector<std::vector<Boardcell>> boardCells;
    static Board* getInstance();
    void initializeBoard();
    void displayBoard();
    void updateBoard();
    void updatePossibleMoves();
    bool movePiece(int startX, int startY, int endX, int endY);
    ~Board();
private:
    //Signleton instance
    static Board* instance;
    Board();
};