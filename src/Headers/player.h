#pragma once
#include <vector>
#include <string>
#include <utility>
#include "piece.h"
using namespace std;

// Forward declaration to avoid circular inclusion
class Manager;

class Player {
public:
    std::string name;
    bool isWhite;
    Manager* manager;
    Player(string name, bool isWhite);
    void addPiece(Piece* piece);
    void removePiece(Piece* piece);
    void displayPieces();
    void movePiece(pair<string, int> startPos, pair<string, int> endPos);
    void requestUndo();
    void acceptUndo();
    ~Player() = default;
};