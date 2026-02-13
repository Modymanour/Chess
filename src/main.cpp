#include <iostream>
#include "Headers/board.h"
#include "Headers/piece.h"
#include "Headers/player.h"
#include "Headers/pawn.h"
#include "Headers/whitepieces.h"
#include "Headers/manager.h"
using namespace std;

int main() {
    cout << "Hello, Chess!" << endl;
    Manager* manager = Manager::getInstance();
    manager->initializeGame();
    manager->displayPieces();
    manager->startGame();
    cin.get();
    return 0;
}   