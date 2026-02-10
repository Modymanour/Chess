#pragma once
#include <vector>
#include <string>
#include <utility>
#include "piece.h"
#include "player.h"
//This class is going to be a singleton
class Boardcell {
public:
    bool isEmpty;
    Piece* piece;
    std::pair<std::string, int> position;
    Boardcell(std::pair<std::string, int> position);
    void assignPiece(Piece* piece);
    void removePiece();
};