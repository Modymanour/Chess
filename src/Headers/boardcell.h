#pragma once
#include <vector>
#include <string>
#include <utility>
#include "piece.h"

class Piece;

class Boardcell {
public:
    bool isEmpty;
    Piece* piece;
    std::pair<std::string, int> position;
    std::vector<Piece*> threatenedBy; //pieces that can move to this cell
    Boardcell(std::pair<std::string, int> position);
    void assignPiece(Piece* piece);
    bool isThreatenedByOpponent(bool isWhite);
    void removePiece();
};