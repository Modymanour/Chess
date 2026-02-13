#include "../Headers/bishop.h"
using namespace std;
Bishop::Bishop(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "Bishop";
    abrvName = isWhite ? "WB" : "BB";
    val = 3;
}
bool Bishop::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    if(startPos.first == endPos.first || startPos.second == endPos.second) {
        return false;
    }
    if(startPos.first > "h" || startPos.first < "a" || startPos.second > 8 || startPos.second < 1) {
        return false;
    }
    return false;
}
void Bishop::updatePossibleMoves(const vector<vector<Boardcell>>& board) {
    return;
}
bool Bishop::move(const pair<string, int>& startPos, const pair<string, int>& endPos, vector<vector<Boardcell>>& board) {
    if(!isValidMove(startPos, endPos)) return false ;
    board[endPos.second - 1][endPos.first[0] - 'a'].assignPiece(this);
    board[startPos.second - 1][startPos.first[0] - 'a'].removePiece();
    position = endPos;
    return true;
}
