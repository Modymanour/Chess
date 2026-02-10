#include "../Headers/whitepieces.h"
#include <iostream>
#include <algorithm>
using namespace std;

WhitePieces::WhitePieces(){
    totalCapturedPieces = 0;
}

void WhitePieces::initializePieces(Board* board){
        // Initialize pawns
        for(int i = 0; i < 8; i++){
            pieces.push_back(new Pawn(true, board->boardCells[1][i].position));
            board->boardCells[1][i].assignPiece(pieces.back());
        }
        // Initialize other pieces  
        // Rooks, Knights, Bishops, Queen, King
        pieces.push_back(new Rook(true,
             board->boardCells[0][0].position));
        board->boardCells[0][0].assignPiece(pieces.back());
        pieces.push_back(new Knight(true,
             board->boardCells[0][1].position));
        board->boardCells[0][1].assignPiece(pieces.back());
        pieces.push_back(new Bishop(true,
             board->boardCells[0][2].position));
        board->boardCells[0][2].assignPiece(pieces.back());
        pieces.push_back(new Queen(true,
             board->boardCells[0][3].position));
        board->boardCells[0][3].assignPiece(pieces.back());
        pieces.push_back(new King(true,
             board->boardCells[0][4].position));
        board->boardCells[0][4].assignPiece(pieces.back());
        pieces.push_back(new Bishop(true,
             board->boardCells[0][5].position));
        board->boardCells[0][5].assignPiece(pieces.back());
        pieces.push_back(new Knight(true,
             board->boardCells[0][6].position));
        board->boardCells[0][6].assignPiece(pieces.back());
        pieces.push_back(new Rook(true,
             board->boardCells[0][7].position));
        board->boardCells[0][7].assignPiece(pieces.back());
    }

    void WhitePieces::displayPieces(){
        for(Piece* piece : pieces){
            cout << piece->abrvName << " at " << piece->position.first << piece->position.second << endl;
        }
    }

    void WhitePieces::addPiece(Piece* piece){
        pieces.push_back(piece);
    }   
    void WhitePieces::removePiece(Piece* piece){
        pieces.erase(remove(pieces.begin(), pieces.end(), piece), pieces.end());
    }
    void WhitePieces::movePiece(pair<string, int> startPos, pair<string, int> endPos){
        if(startPos == endPos) {
            cout << "Invalid move: Start and end positions are the same." << endl;
            return;
        }
        if(startPos.first < "a" || startPos.first > "h" || startPos.second < 1 || startPos.second > 8 ||
           endPos.first < "a" || endPos.first > "h" || endPos.second < 1 || endPos.second > 8) {
            cout << "Invalid move: Position out of bounds." << endl;
            return;
        }
        Piece* pieceToMove = nullptr;
        for(Piece* piece : pieces){
            if(piece->position == startPos){
                pieceToMove = piece;
                break;
            }
        }
        if(pieceToMove == nullptr){
            cout << "Invalid move: No piece at the starting position." << endl;
            return;
        }
        if(!pieceToMove->isValidMove(startPos, endPos)){
            cout << "Invalid move: Move not valid for the piece." << endl;
            return;
        }
        pieceToMove->move(startPos, endPos);
        cout << "Moved " << pieceToMove->abrvName << " from " << startPos.first << startPos.second << " to " << endPos.first << endPos.second << endl;
    }