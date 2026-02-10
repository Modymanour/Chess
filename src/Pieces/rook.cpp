#include "../Headers/rook.h"
#include <bits/stdc++.h>
using namespace std;
Rook::Rook(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    this->name = "Rook";
    this->abrvName = isWhite ? "WR" : "BR";
    this->val = 5;
}

bool Rook::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    if(startPos.first == endPos.first || startPos.second == endPos.second) {
        return false;
    }
    if(startPos.first > "h" || startPos.first < "a" || startPos.second > 8 || startPos.second < 1) {
        return false;
    }
    //still to be made
    return true;
}
void Rook::updatePossibleMoves(const vector<pair<string, int>>& board) {
    return;
}
void Rook::move(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return;
}