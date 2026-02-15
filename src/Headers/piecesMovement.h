#pragma once
#include <bits/stdc++.h>
#include "piece.h"
using namespace std;
class movement {
public:
    static vector<pair<string, int>> horizontalMove(const std::pair<std::string, int>& startPos,
          vector<vector<Boardcell>>& board);
    static vector<pair<string, int>> verticalMove(const std::pair<std::string, int>& startPos,
          vector<vector<Boardcell>>& board);
    static vector<pair<string, int>> diagonalMove(const std::pair<std::string, int>& startPos,
          vector<vector<Boardcell>>& board);
    static vector<pair<string, int>> knightMove(const std::pair<std::string, int>& startPos,
          vector<vector<Boardcell>>& board);
     static vector<pair<string, int>> kingMove(const std::pair<std::string, int>& startPos,
          vector<vector<Boardcell>>& board);
};