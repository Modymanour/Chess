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
#include "board.h"

class Board;

class BlackPieces {
public:
    std::vector<Piece*> pieces;
    int totalCapturedPieces;
    Board* board;
    BlackPieces();
    void initializePieces(Board* board);
    void displayPieces();
    void addPiece(Piece* piece);
    void removePiece(Piece* piece);
    void movePiece(std::pair<std::string, int> startPos, std::pair<std::string, int> endPos);
    ~BlackPieces();
};