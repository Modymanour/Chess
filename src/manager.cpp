#include "Headers/manager.h"
#include <iostream>
#include <unistd.h>
using namespace std;
Manager* Manager::instance = nullptr;
Manager::Manager() {
    board = nullptr;
}
Manager* Manager::getInstance() {
    if (instance == nullptr) {
        instance = new Manager();
        instance->initializeGame();
    }
    return instance;
}
void Manager::initializeGame() {
    if(board == nullptr)board = Board::getInstance();
    else board->resetEverything();
    board->initializeBoard();
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
    board->updateBoard();
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
}
void Manager::startGame() {
    string startPos, endPos, pos;
    int choice;
    while (true) {
        board->displayBoard();
        if (board->isWhiteTurn) {
            cout << "White's turn" << endl;
        } else {
            cout << "Black's turn" << endl;
        }
        if(board->isGameOver){
            string whoWon = board->isWhiteTurn ? "White" : "Black";
            cout<<"Good game fellas\n";
            sleep(0.2);
            cout << whoWon << " Won!!"<<endl;
            int whatNow;
            cout << "1. another game?" << endl;
            cout << "2. Leave" << endl;
            cin >> whatNow;
            switch(whatNow){
                case 1: {
                    this->initializeGame();
                }
            }
        }
        cout << "1. Make a move" << endl;
        cout << "2. Display possible moves for a piece" << endl;
        cout << "3. Display Dead Pieces" << endl;
        cout << "4. Save game" << endl;
        cout << "5. Load game" << endl;
        cout << "6. Quit game" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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
            case 3 : {
                board->viewDeadPieces();
            }
            case 4:
                saveGame();
                break;
            case 5:
                loadGame();
                break;
            case 6:
                endGame();
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
        sleep(0.5);
    }
}