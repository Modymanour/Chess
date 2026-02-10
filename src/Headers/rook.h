#pragma once
#include <vector>
#include "piece.h"
#include "board.h"
class Rook : public Piece {
public:
    Rook(bool isWhite, pair<string, int> position);
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void updatePossibleMoves(const vector<pair<string, int>>& board) override;
    void move(const pair<string, int>& startPos, const pair<string, int>& endPos) override;
    ~Rook() = default;
};