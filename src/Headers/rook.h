#pragma once
#include <vector>
#include <utility>
#include "piece.h"
class Rook : public Piece {
public:
    Rook(bool isWhite, std::pair<std::string, int> position);
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void updatePossibleMoves(const std::vector<std::pair<std::string, int>>& board) override;
    void move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    ~Rook() = default;
};