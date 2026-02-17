#pragma once
#include "boardcell.h"
#include <vector>
#include <string>

class Boardcell;

class Piece {
public:
    int val;
    std::string name;
    std::string abrvName;
    bool isWhite;
    std::pair<std::string, int> position;
    std::vector<std::pair<std::string, int>> possibleMoves;
    // Pin-related fields
    bool isPinned;
    std::pair<std::string, int> pinDirection; // Direction of the pin (e.g., "vertical", "horizontal", "diagonal")
    Piece(bool isWhite, std::pair<std::string, int> position);
    virtual bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) = 0;
    virtual void updatePossibleMoves(std::vector<std::vector<Boardcell>>& board) = 0;
    virtual bool move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos, std::vector<std::vector<Boardcell>>& board);
    virtual ~Piece();
};