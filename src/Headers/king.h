#pragma once
#include <vector>
#include <utility>
#include "piece.h"
class King : public Piece {
public:
    King(bool isWhite, std::pair<std::string, int> position);
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void updatePossibleMoves(std::vector<std::vector<Boardcell>>& board) override;
    bool move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos, std::vector<std::vector<Boardcell>>& board) override;
    ~King () = default;
};