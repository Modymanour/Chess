#include "../Headers/pawn.h"
using namespace std;

Pawn::Pawn(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "Pawn";
    abrvName = isWhite ? "WP" : "BP";
    val = 1;
}

void Pawn::updatePossibleMoves(const vector<pair<string, int>>& board) {
    return;
}

bool Pawn::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return false;
}

void Pawn::move(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return;
}