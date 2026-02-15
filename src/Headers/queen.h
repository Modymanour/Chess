#pragma once
#include <vector>
#include <utility>
#include "piece.h"
#include "piecesMovement.h"
class Queen : public Piece {
public:
    Queen(bool isWhite, std::pair<std::string, int> position);
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void updatePossibleMoves(std::vector<std::vector<Boardcell>>& board) override;
    bool move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos,std::vector<std::vector<Boardcell>>& board) override;
    ~Queen () = default;
};