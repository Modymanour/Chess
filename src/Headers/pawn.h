#pragma once
#include <vector>
#include <utility>
#include "piece.h"
class Pawn : public Piece {
    bool hasMoved = false;
public:
    Pawn(bool isWhite, std::pair<std::string, int> position);
    void updatePossibleMoves(const std::vector<std::pair<std::string, int>>& board) override;
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    ~Pawn() = default;
};