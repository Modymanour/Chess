#pragma once
#include <vector>
#include <string>
#include <utility>
#include "piece.h"
#include "blackpieces.h"
#include "whitePieces.h"
using namespace std;
class Player {
public:
    std::string name;
    bool isWhite;
    WhitePieces* whitePieces;
    BlackPieces* blackPieces;
    Player(string name, bool isWhite);
    void addPiece(Piece* piece);
    void removePiece(Piece* piece);
    void displayPieces();
    void movePiece(pair<string, int> startPos, pair<string, int> endPos);
    void requestUndo();
    void acceptUndo();
    ~Player() = default;
};