#pragma once
#include <vector>
#include <utility>
#include "piece.h"
#include "board.h"
class King : public Piece {
public:
    King(bool isWhite, pair<string, int> position);
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void updatePossibleMoves(const vector<pair<string, int>>& board) override;
    void move(const pair<string, int>& startPos, const pair<string, int>& endPos) override;
    ~King () = default;
};