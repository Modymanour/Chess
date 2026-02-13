#include "../Headers/king.h"
using namespace std;
King::King(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "King";
    abrvName = isWhite ? "WK" : "BK";
    val = 1000;
}
bool King::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    if(startPos.first == endPos.first || startPos.second == endPos.second) {
        return false;
    }
    if(startPos.first > "h" || startPos.first < "a" || startPos.second > 8 || startPos.second < 1) {
        return false;
    }
    return false;
}
void King::updatePossibleMoves(const vector<vector<Boardcell>>& board) {
    return;
}
bool King::move(const pair<string, int>& startPos, const pair<string, int>& endPos, vector<vector<Boardcell>>& board) {
    if(!isValidMove(startPos, endPos)) return false ;
    board[endPos.second - 1][endPos.first[0] - 'a'].assignPiece(this);
    board[startPos.second - 1][startPos.first[0] - 'a'].removePiece();
    position = endPos;
    return true;
}
