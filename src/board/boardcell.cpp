#include "boardcell.h"
Boardcell::Boardcell(std::pair<std::string, int> position) {
    this->position = position;
    this->isEmpty = true;
    this->piece = nullptr;
}
void Boardcell::assignPiece(Piece* piece) {
    this->piece = piece;
    this->isEmpty = false;
}
void Boardcell::removePiece() {
    this->piece = nullptr;
    this->isEmpty = true;
}
bool Boardcell::isThreatenedByOpponent(bool isWhite) {
    for(auto& piece : threatenedBy) {
        if(piece->isWhite != isWhite) {
            return true;
        }
    }
    return false;
}