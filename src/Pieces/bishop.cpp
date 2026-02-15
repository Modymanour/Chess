#include "../Headers/bishop.h"
using namespace std;
Bishop::Bishop(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "Bishop";
    abrvName = isWhite ? "WB" : "BB";
    val = 3;
}
bool Bishop::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return find(possibleMoves.begin(), possibleMoves.end(), endPos) != possibleMoves.end();
}
void Bishop::updatePossibleMoves( vector<vector<Boardcell>>& board) {
    possibleMoves.clear();
    vector<pair<string, int>> diagonalMoves = movement::diagonalMove(position, board);
    possibleMoves.insert(possibleMoves.end(), diagonalMoves.begin(), diagonalMoves.end());
}
bool Bishop::move(const pair<string, int>& startPos, const pair<string, int>& endPos, vector<vector<Boardcell>>& board) {
    if(!isValidMove(startPos, endPos)) return false ;
    board[endPos.second - 1][endPos.first[0] - 'a'].assignPiece(this);
    board[startPos.second - 1][startPos.first[0] - 'a'].removePiece();
    position = endPos;
    return true;
}
