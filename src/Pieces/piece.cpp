#include "../Headers/piece.h"
using namespace std;

Piece::Piece(bool isWhite, pair<string, int> position){
    this->isWhite = isWhite;
    this->position = position;
}

Piece::~Piece() {
}

void Piece::move(const pair<string, int>& startPos, const pair<string, int>& endPos) {
}