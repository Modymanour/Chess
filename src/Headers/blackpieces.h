#pragma once
#include <vector>
#include <utility>
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "player.h"

//to stop circular dependency
class Board;

class BlackPieces {
public:
    std::vector<Piece*> pieces;
    Player* player;
    int totalCapturedPieces;
    BlackPieces();
    void initializePieces(Board* board, Player* player);
    void displayPieces();
    void addPiece(Piece* piece);
    void removePiece(Piece* piece);
    void movePiece(pair<std::string, int> startPos, pair<std::string, int> endPos);
    ~BlackPieces();
};