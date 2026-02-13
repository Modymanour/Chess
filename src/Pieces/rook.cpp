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
    return false;
}
void Rook::updatePossibleMoves(const vector<vector<Boardcell>>& board) {
    return;
}
bool Rook::move(const pair<string, int>& startPos, const pair<string, int>& endPos, vector<vector<Boardcell>>& board) {
    if(!isValidMove(startPos, endPos)) return false ;
    board[endPos.second - 1][endPos.first[0] - 'a'].assignPiece(this);
    board[startPos.second - 1][startPos.first[0] - 'a'].removePiece();
    position = endPos;
    return true;
}