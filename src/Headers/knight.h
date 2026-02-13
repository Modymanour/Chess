#pragma once
#include <vector>
#include <utility>
#include "piece.h"
class Knight : public Piece {
public:
    Knight(bool isWhite, std::pair<std::string, int> position);
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void updatePossibleMoves(const std::vector<std::vector<Boardcell>>& board) override;
    bool move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos,std::vector<std::vector<Boardcell>>& board) override;
    ~Knight () = default;
};