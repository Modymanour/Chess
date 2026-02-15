#include "../Headers/knight.h"
using namespace std;

Knight::Knight(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "Knight";
    abrvName = isWhite ? "WKN" : "BKN";
    val = 3;
}
bool Knight::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return find(possibleMoves.begin(), possibleMoves.end(), endPos) != possibleMoves.end();
}
void Knight::updatePossibleMoves(vector<vector<Boardcell>>& board) {
    possibleMoves.clear();
    vector<pair<string, int>> knightMoves = movement::knightMove(position, board);
    possibleMoves.insert(possibleMoves.end(), knightMoves.begin(), knightMoves.end());
}
bool Knight::move(const pair<string, int>& startPos, const pair<string, int>& endPos, vector<vector<Boardcell>>& board) {
    if(!isValidMove(startPos, endPos)) return false ;
    board[endPos.second - 1][endPos.first[0] - 'a'].assignPiece(this);
    board[startPos.second - 1][startPos.first[0] - 'a'].removePiece();
    position = endPos;
    return true;
}