#include "../Headers/blackpieces.h"
#include <iostream>
#include <algorithm>
using namespace std;

BlackPieces::BlackPieces(){
    totalCapturedPieces = 0;
}

void BlackPieces::initializePieces(Board* board){
        this->board = board;
        // Initialize pawns
        for(int i = 0; i < 8; i++){
            pieces.push_back(new Pawn(false, board->boardCells[6][i].position));
            board->boardCells[6][i].assignPiece(pieces.back());
        }
        // Initialize other pieces  
        // Rooks, Knights, Bishops, Queen, King
        pieces.push_back(new Rook(false,
             board->boardCells[7][0].position));
        board->boardCells[7][0].assignPiece(pieces.back());
        pieces.push_back(new Knight(false,
             board->boardCells[7][1].position));
        board->boardCells[7][1].assignPiece(pieces.back());
        pieces.push_back(new Bishop(false,
             board->boardCells[7][2].position));
        board->boardCells[7][2].assignPiece(pieces.back());
        pieces.push_back(new Queen(false,
             board->boardCells[7][3].position));
        board->boardCells[7][3].assignPiece(pieces.back());
        pieces.push_back(new King(false,
             board->boardCells[7][4].position));
        board->boardCells[7][4].assignPiece(pieces.back());
        pieces.push_back(new Bishop(false,
             board->boardCells[7][5].position));
        board->boardCells[7][5].assignPiece(pieces.back());
        pieces.push_back(new Knight(false,
             board->boardCells[7][6].position));
        board->boardCells[7][6].assignPiece(pieces.back());
        pieces.push_back(new Rook(false,
             board->boardCells[7][7].position));
        board->boardCells[7][7].assignPiece(pieces.back());
    }

    void BlackPieces::displayPieces(){
        for(Piece* piece : pieces){
            cout << piece->abrvName << " at " << piece->position.first << piece->position.second << endl;
        }
    }

    void BlackPieces::addPiece(Piece* piece){
        pieces.push_back(piece);
    }   
    void BlackPieces::removePiece(Piece* piece){
        pieces.erase(remove(pieces.begin(), pieces.end(), piece), pieces.end());
    }
    void BlackPieces::movePiece(pair<string, int> startPos, pair<string, int> endPos){
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
        pieceToMove->move(startPos, endPos, board->boardCells);
        cout << "Moved " << pieceToMove->abrvName << " from " << startPos.first << startPos.second << " to " << endPos.first << endPos.second << endl;
    }