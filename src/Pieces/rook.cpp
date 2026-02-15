#include "../Headers/rook.h"
#include <bits/stdc++.h>
using namespace std;
Rook::Rook(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    this->name = "Rook";
    this->abrvName = isWhite ? "WR" : "BR";
    this->val = 5;
}

bool Rook::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
   return find(possibleMoves.begin(), possibleMoves.end(), endPos) != possibleMoves.end();
}
void Rook::updatePossibleMoves(vector<vector<Boardcell>>& board) {
    possibleMoves.clear();
    vector<pair<string, int>> horizontalMoves = movement::horizontalMove(position, board);
    vector<pair<string, int>> verticalMoves = movement::verticalMove(position, board);
    possibleMoves.insert(possibleMoves.end(), horizontalMoves.begin(), horizontalMoves.end());
    possibleMoves.insert(possibleMoves.end(), verticalMoves.begin(), verticalMoves.end());
}
bool Rook::move(const pair<string, int>& startPos, const pair<string, int>& endPos, vector<vector<Boardcell>>& board) {
    if(!isValidMove(startPos, endPos)) return false ;
    board[endPos.second - 1][endPos.first[0] - 'a'].assignPiece(this);
    board[startPos.second - 1][startPos.first[0] - 'a'].removePiece();
    position = endPos;
    return true;
}