#include <iostream>
#include "../Headers/board.h"
#include <iomanip>
using namespace std;

Board* Board::instance = nullptr;
Board::Board() {
    isWhiteTurn = true;
}
Board* Board::getInstance() {
    if (instance == nullptr) {
        instance = new Board();
        instance->initializeBoard();
    }
    return instance;
}

void Board::initializeBoard() {
    boardCells.clear();
    for (int i = 0; i < 8; i++) {
        vector<Boardcell> row;
        for (int j = 0; j < 8; j++) {
            //intiates the cells with a1 -> b1 -> c1 ... h8 then a2 -> b2 -> c2 ... h8 and so on
            row.push_back(Boardcell(std::make_pair(string(1, "abcdefgh"[j]), i + 1)));
        }
        boardCells.push_back(row);
    }
}

void Board::displayBoard() {
    if(isWhiteTurn) {
        //white's prespective
        for(int i=0; i<8;i++){
            cout << setw(5) << string(1, "abcdefgh"[i]);
        }
        cout << endl;
        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                if (boardCells[i][j].isEmpty) {
                    cout << setw(5) << ".";
                } else {
                    cout << setw(5) << boardCells[i][j].piece->abrvName;
                }
            }
            cout << setw(3) << i+1 <<  endl;
        }
    }
    else{
        //black's prespective
        for(int i=0; i<8;i++){
            cout << setw(5) << string(1, "hgfedcba"[i]);
        }
        cout << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (boardCells[i][j].isEmpty) {
                    cout << setw(5) << ".";
                } else {
                    cout << setw(5) << boardCells[i][j].piece->abrvName;
                }
            }
            cout << setw(3) << 8-i <<  endl;
        }
    }
    
}
void Board::displayPieces(){
    for(auto& row : boardCells) {
        for(auto& cell : row) {
            if(!cell.isEmpty) {
                cout <<"---" << cell.piece->abrvName << " " << cell.position.first << cell.position.second << " Possible Moves: ";
                for(auto& move : cell.piece->possibleMoves) {
                    cout << move.first << move.second << " ";
                }
                cout << endl;
            }
        }
    }
}
void Board::updateBoard() {
}

void Board::updatePossibleMoves() {
    for(auto& row : boardCells) {
        for(auto& cell : row) {
            if(!cell.isEmpty) {
                cell.piece->updatePossibleMoves(boardCells);
            }
        }
    }
}

bool Board::movePiece(pair<std::string, int> startPos, pair<std::string, int> endPos) {
    Piece* piece = boardCells[startPos.second - 1][startPos.first[0] - 'a'].piece;
    if(piece == nullptr){
        cout << "No piece at the starting position." << endl;
        return false;
    }
    if(piece->isWhite != isWhiteTurn){
        cout << "It's not your turn." << endl;
        return false;
    }
    if(!piece->move(startPos, endPos, boardCells)){
        return false;
    }
    return true;
}

Board::~Board() {
}