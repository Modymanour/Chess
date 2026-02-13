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
    board->updatePossibleMoves();
}
void Manager::displayBoard() {
    board->displayBoard();
}
void Manager::displayPiecePossibleMoves(pair<string, int> position) {
    for(auto& row : board->boardCells) {
        for(auto& cell : row) {
            if(!cell.isEmpty && cell.position == position) {
                cout << "Possible moves for " << cell.piece->abrvName << " at " << cell.position.first << cell.position.second << ":" << endl;
                for(auto& move : cell.piece->possibleMoves) {
                    cout << move.first << move.second << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    cout << "No piece found at the given position." << endl;
}
void Manager::displayPieces() {
    board->displayPieces();
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
        cout << "Enter move (e.g., e2 e4): ";
        cin >> startPos >> endPos;
        makeMove({startPos.substr(0, 1), stoi(startPos.substr(1))}, {endPos.substr(0, 1), stoi(endPos.substr(1))});
    }
}
void Manager::switchTurn() {
    isWhiteTurn = !isWhiteTurn;
    board->isWhiteTurn = isWhiteTurn;
    board->updatePossibleMoves();
}
void Manager::makeMove(std::pair<std::string, int> startPos, std::pair<std::string, int> endPos) {
    if(board->movePiece(startPos, endPos)) {
        switchTurn();
    } else {
        cout << "Invalid move try again." << endl;
    }
}
void Manager::saveGame() {

}
void Manager::loadGame() {

}
void Manager::endGame() {
    isGameOver = true;
}