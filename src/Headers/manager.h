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
    void startGame();
    void switchTurn();
    void saveGame();
    void loadGame();
    void endGame();
private:
    static Manager* instance;
    Manager();
};