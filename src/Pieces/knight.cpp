#include "../Headers/knight.h"
using namespace std;

Knight::Knight(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "Knight";
    abrvName = isWhite ? "WKN" : "BKN";
    val = 3;
}
bool Knight::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    if(startPos.first == endPos.first || startPos.second == endPos.second) {
        return false;
    }
    if(startPos.first > "h" || startPos.first < "a" || startPos.second > 8 || startPos.second < 1) {
        return false;
    }
    return false;
}
void Knight::updatePossibleMoves(const vector<pair<string, int>>& board) {
    return;
}
void Knight::move(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return;
}