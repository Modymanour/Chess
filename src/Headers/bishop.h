#pragma once
#include <vector>
#include <utility>
#include "piece.h"
#include "piecesMovement.h"
class Bishop : public Piece {
public:
    Bishop(bool isWhite, std::pair<std::string, int> position);
    bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) override;
    void updatePossibleMoves(const std::vector<std::vector<Boardcell>>& board) override;
    bool move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos,std::vector<std::vector<Boardcell>>& board) override;
    ~Bishop () = default;
};