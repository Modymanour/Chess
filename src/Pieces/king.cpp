#include "../Headers/king.h"
#include "../Headers/piecesMovement.h"
using namespace std;
King::King(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "King";
    abrvName = isWhite ? "WK" : "BK";
    val = 1000;
}
bool King::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return find(possibleMoves.begin(), possibleMoves.end(), endPos) != possibleMoves.end();
}
void King::updatePossibleMoves(vector<vector<Boardcell>>& board) {
    possibleMoves.clear();
    vector<pair<string,int>> kingMoves = movement::kingMove(position, board);
    possibleMoves.insert(possibleMoves.end(), kingMoves.begin(), kingMoves.end());
}
bool King::move(const pair<string, int>& startPos, const pair<string, int>& endPos, vector<vector<Boardcell>>& board) {
    if(!isValidMove(startPos, endPos)) return false ;
    board[endPos.second - 1][endPos.first[0] - 'a'].assignPiece(this);
    board[startPos.second - 1][startPos.first[0] - 'a'].removePiece();
    position = endPos;
    return true;
}
