#pragma once
#include <vector>
#include <string>
class Piece {
public:
    int val;
    std::string name;
    std::string abrvName;
    bool isWhite;
    std::pair<std::string, int> position;
    std::vector<std::pair<std::string, int>> possibleMoves;
    Piece(bool isWhite, std::pair<std::string, int> position);
    virtual void updatePossibleMoves(const std::vector<std::pair<std::string, int>>& board) = 0;
    virtual bool isValidMove(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos) = 0;
    virtual void move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos);
    virtual ~Piece();
};