#include "../Headers/piece.h"
using namespace std;

Piece::Piece(bool isWhite, pair<string, int> position){
    this->isWhite = isWhite;
    this->position = position;
    this->hasMoved = false;
    this->isPinned = false;
    this->pinDirection = make_pair("none", 0);
}

Piece::~Piece() {
}

bool Piece::move(const pair<string, int>& startPos, const pair<string, int>& endPos, vector<vector<Boardcell>>& board) {
    return false;
}