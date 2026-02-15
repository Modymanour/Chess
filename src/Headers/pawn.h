#pragma once
#include <bits/stdc++.h>
#include <utility>
#include "piece.h"
class Pawn : public Piece {
    bool hasMoved = false;
public:
    Pawn(bool isWhite, std::pair<std::string, int> position);
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void updatePossibleMoves(std::vector<std::vector<Boardcell>>& board) override;
    bool move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos,std::vector<std::vector<Boardcell>>& board) override;
    ~Pawn() = default;
};