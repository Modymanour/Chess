#include "../Headers/queen.h"
using namespace std;
Queen::Queen(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "Queen";
    abrvName = isWhite ? "WQ" : "BQ";
    val = 9;
}
bool Queen::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    if(startPos.first == endPos.first || startPos.second == endPos.second) {
        return false;
    }
    if(startPos.first > "h" || startPos.first < "a" || startPos.second > 8 || startPos.second < 1) {
        return false;
    }
    return true;
}
void Queen::updatePossibleMoves(const vector<pair<string, int>>& board) {
    return;
}
void Queen::move(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return;
}
