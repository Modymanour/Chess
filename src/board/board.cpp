#include <iostream>
#include "../Headers/board.h"
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
            row.push_back(Boardcell(std::make_pair(string(1, "abcdefgh"[j]), 8 - i)));
        }
        boardCells.push_back(row);
    }
}

void Board::displayBoard() {
    if(isWhiteTurn) {
        //white's prespective
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (boardCells[i][j].isEmpty) {
                    cout << ". ";
                } else {
                    cout << boardCells[i][j].piece->abrvName << " ";
                }
            }
            cout << 8-i <<  endl;
        }
    }
    else{
        //black's prespective
        for (int i = 8; i > 0; i--) {
            for (int j = 8; j > 0; j--) {
                if (boardCells[i][j].isEmpty) {
                    cout << ". ";
                } else {
                    cout << boardCells[i][j].piece->abrvName << " ";
                }
            }
            cout << i <<  endl;
        }
    }
    
}

void Board::updateBoard() {
}

void Board::updatePossibleMoves() {
}

bool Board::movePiece(int startX, int startY, int endX, int endY) {
    return false;
}

Board::~Board() {
}