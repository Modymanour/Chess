#include "../Headers/pawn.h"
using namespace std;

Pawn::Pawn(bool isWhite, pair<string, int> position) : Piece(isWhite, position) {
    name = "Pawn";
    abrvName = isWhite ? "WP" : "BP";
    val = 1;
}

void Pawn::updatePossibleMoves(std::vector<std::vector<Boardcell>>& board) { // needs optimiztion
    possibleMoves.clear();
    string col = position.first;
    int row = position.second - 1;
    int direction = isWhite ? 1 : -1; //white moves up, black moves down
    // cout << "Updating possible moves for " << abrvName << " at " << position.first << position.second << " direction:"<<direction << " "<<this->isWhite<< endl;

    //check if the cell in front of the pawn is empty, if it is add it to possible moves
    if(board[row + direction][col[0]-'a'].isEmpty) {
        possibleMoves.push_back(make_pair(col,row + direction+1));
        //check if the pawn haven't moved yet to give it the option to move 2 cells forward
        if(!hasMoved){
            if(board[row + 2*direction][col[0]-'a'].isEmpty) {
                possibleMoves.push_back(make_pair(col,row + 2*direction+1));
            }
        }
    }
    
    
    //check if the diagonal cells have an opponent piece to capture
    if(col != "a" && !board[row + direction][col[0]-'a'-1].isEmpty && board[row + direction][col[0]-'a'-1].piece->isWhite != isWhite) {
        possibleMoves.push_back(make_pair(string(1, col[0]-1), row + direction+1));
    }
    if(col != "h" && !board[row + direction][col[0]-'a'+1].isEmpty && board[row + direction][col[0]-'a'+1].piece->isWhite != isWhite) {
        possibleMoves.push_back(make_pair(string(1, col[0]+1), row + direction+1));
    }
    if(col != "a" && col != "h" && row + direction >= 0 && row + direction < 8) {
        if(board[row + direction][col[0]-'a'-1].isEmpty || board[row + direction][col[0]-'a'-1].piece->isWhite != isWhite) {
            board[row + direction][col[0]-'a'-1].threatenedBy.push_back(this);
        }
        if(board[row + direction][col[0]-'a'+1].isEmpty || board[row + direction][col[0]-'a'+1].piece->isWhite != isWhite) {
            board[row + direction][col[0]-'a'+1].threatenedBy.push_back(this);
        }
    }
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