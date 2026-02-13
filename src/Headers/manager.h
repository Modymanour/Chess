#pragma once
#include "board.h"
#include "player.h"
//This class is going to be a singleton
class Manager {
    public:
    Board* board;
    WhitePieces* whitePieces;
    BlackPieces* blackPieces;
    bool isWhiteTurn;
    bool isGameOver;
    static Manager* getInstance();
    void initializeGame();
    void displayBoard();
    void displayPiecePossibleMoves(std::pair<std::string, int> position);
    void displayPieces();
    void startGame();
    void switchTurn();
    void makeMove(std::pair<std::string, int> startPos, std::pair<std::string, int> endPos);
    void saveGame();
    void loadGame();
    void endGame();
private:
    static Manager* instance;
    Manager();
};