#include "../Headers/pawn.h"
using namespace std;

Pawn::Pawn(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "Pawn";
    abrvName = isWhite ? "WP" : "BP";
    val = 1;
}

void Pawn::updatePossibleMoves(std::vector<std::vector<Boardcell>>& board) { // needs optimiztion
    possibleMoves.clear();
    possibleMoves = movement::pawnMove(position, board);
}

bool Pawn::isValidMove(const pair<string, int>& startPos, const pair<string, int>& endPos) {
    return find(possibleMoves.begin(), possibleMoves.end(), endPos) != possibleMoves.end();
}

bool Pawn::move(const std::pair<std::string, int>& startPos, const std::pair<std::string, int>& endPos, std::vector<std::vector<Boardcell>>& board) {
    if(!isValidMove(startPos, endPos)) return false ;
    hasMoved = true;
    board[endPos.second - 1][endPos.first[0] - 'a'].assignPiece(this);
    board[startPos.second - 1][startPos.first[0] - 'a'].removePiece();
    position = endPos;
    return true;
}