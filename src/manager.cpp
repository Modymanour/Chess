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
void Manager::startGame() {
    string startPos, endPos, pos;
    int choice;
    while (!isGameOver) {
        board->displayBoard();
        if (isWhiteTurn) {
            cout << "White's turn" << endl;
        } else {
            cout << "Black's turn" << endl;
        }
        cout << "1. Make a move" << endl;
        cout << "2. Display possible moves for a piece" << endl;
        cout << "3. Save game" << endl;
        cout << "4. Load game" << endl;
        cout << "5. Quit game" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter move (e.g., e2 e4): ";
                cin >> startPos >> endPos;
                if (cin.fail() || startPos.length() < 2 || endPos.length() < 2) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input format. Try again." << endl;
                } else {
                    makeMove({startPos.substr(0, 1), stoi(startPos.substr(1))}, {endPos.substr(0, 1), stoi(endPos.substr(1))});
                }
                break;
            case 2: {
                cout << "Enter piece position (e.g., e2): ";
                cin >> pos;
                if (cin.fail() || pos.length() < 2) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input format. Try again." << endl;
                } else {
                    displayPiecePossibleMoves({pos.substr(0, 1), stoi(pos.substr(1))});
                }
                break;
            }
            case 3:
                saveGame();
                break;
            case 4:
                loadGame();
                break;
            case 5:
                endGame();
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}