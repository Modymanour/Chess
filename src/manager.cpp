#include "Headers/manager.h"
#include <iostream>
using namespace std;
Manager* Manager::instance = nullptr;
Manager::Manager() {
    board = nullptr;
    whitePieces = nullptr;
    blackPieces = nullptr;
    isWhiteTurn = true;
    isGameOver = false;
}
Manager* Manager::getInstance() {
    if (instance == nullptr) {
        instance = new Manager();
        instance->initializeGame();
    }
    return instance;
}
void Manager::initializeGame() {
    isWhiteTurn = true;
    board = Board::getInstance();
    if(whitePieces == nullptr) whitePieces = new WhitePieces();
    else whitePieces->pieces.clear();
    if(blackPieces == nullptr) blackPieces = new BlackPieces();
    else blackPieces->pieces.clear();
    
    whitePieces->initializePieces(board);
    blackPieces->initializePieces(board);
}
void Manager::displayBoard() {
    board->displayBoard();
}
void Manager::startGame() {
    while (!isGameOver) {
        board->displayBoard();
        if (isWhiteTurn) {
            cout << "White's turn" << endl;
        } else {
            cout << "Black's turn" << endl;
        }
        string startPos, endPos;
    }
}
void Manager::switchTurn() {
    isWhiteTurn = !isWhiteTurn;
}
void Manager::saveGame() {

}
void Manager::loadGame() {

}
void Manager::endGame() {
    isGameOver = true;
}