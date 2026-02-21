#include <iostream>
#include "../Headers/board.h"
#include <iomanip>
using namespace std;

Board* Board::instance = nullptr;
Board::Board() {
    isWhiteTurn = true;
    whitePieces = nullptr;
    blackPieces = nullptr;
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
    if(whitePieces == nullptr) whitePieces = new WhitePieces();
    if(blackPieces == nullptr) blackPieces = new BlackPieces();
    whitePieces->initializePieces(this);
    blackPieces->initializePieces(this);
    for(auto& row : boardCells) {
        for(auto& cell : row) {
            if(!cell.isEmpty) {
                pieces.push_back(cell.piece);
            }
        }
    }
    updatePossibleMoves();
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
        if(isCheck) {
            cout << "White King is in Check!" << endl;
        }
    }
    else{
        //black's prespective
        for(int i=0; i<8;i++){
            cout << setw(5) << string(1, "hgfedcba"[i]);
        }
        cout << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 7; j >= 0; j--) {
                if (boardCells[i][j].isEmpty) {
                    cout << setw(5) << ".";
                } else {
                    cout << setw(5) << boardCells[i][j].piece->abrvName;
                }
            }
            cout << setw(3) << i+1 <<  endl;
        }
        if(isCheck) {
            cout << "Black King is in Check!" << endl;
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
    isWhiteTurn = !isWhiteTurn;
    updatePossibleMoves();
    if(isCheck) isGameOver = isCheckmate(isWhiteTurn,boardCells);
}

void Board::updatePossibleMoves() {//can be optmized by adding pieces to board to upgrade immiedietly
    for(auto& piece : pieces) {
        if(piece == nullptr) continue;
        piece->updatePossibleMoves(boardCells);
        // cout << "Updated possible moves for " << piece->abrvName << " at " << piece->position.first << piece->position.second << ": ";
        if(isPiecePinned(piece, boardCells)) {
            piece->possibleMoves = filterMovesForPin(piece, piece->possibleMoves, boardCells);
        }
        for(auto& move : piece->possibleMoves) {
            cout << move.first << move.second << " ";
        }
        cout << endl;
    }
    isCheck = isKingInCheck(isWhiteTurn, boardCells);
    vector<pair<string, int>> checkPath;
    if (isCheck) {
        checkPath = kingCheckPath(boardCells);
        for(auto& cell : checkPath) {
            // cout << "Check path includes: " << cell.first << cell.second << endl;
        }
        for(auto& piece : pieces) {
            if(piece->name != "King" && piece->isWhite == isWhiteTurn) {
                piece->possibleMoves = filterMovesForCheck(piece, checkPath, boardCells);
                // cout << "filtered : " << piece->abrvName << " at " << piece->position.first << piece->position.second << " Possible Moves: ";
                // for(auto& move : piece->possibleMoves) {
                //     cout << move.first << move.second << " ";
                // }
                // cout << endl;
            }
        }
    }
    
}

bool Board::movePiece(pair<std::string, int> startPos, pair<std::string, int> endPos) {
    if(startPos.second > 8 || startPos.second < 0) return false;
    Piece* piece = boardCells[startPos.second - 1][startPos.first[0] - 'a'].piece;
    if(piece == nullptr){
        cout << "No piece at the starting position." << endl;
        return false;
    }
    if(piece->isWhite != isWhiteTurn){
        cout << "It's not your turn." << endl;
        return false;
    }
    Piece* deadPiece =  boardCells[endPos.second - 1][endPos.first[0] - 'a'].piece != nullptr ? boardCells[endPos.second - 1][endPos.first[0] - 'a'].piece : nullptr;
    if(!piece->move(startPos, endPos, boardCells)){
        return false;
    }
    killPiece(deadPiece);
    return true;
}

void Board::killPiece(Piece* deadPiece){
    if(deadPiece == nullptr) return;
    this->pieces.erase(find(this->pieces.begin(),this->pieces.end(),deadPiece));
    this->deadPieces.push_back(deadPiece);
}

void Board::viewDeadPieces(){
    if(!deadPieces.empty())
        for(auto& piece : deadPieces)
            cout<< piece->abrvName << " " <<  piece->name  << "died at position " << piece->position.first << piece->position.second << endl;
}


// Find the king of a given color on the board
Piece* Board::findKing(bool isWhite, const vector<vector<Boardcell>>& board) {
    for(const auto& row : board) {
        for(const auto& cell : row) {
            if(!cell.isEmpty && cell.piece->isWhite == isWhite && cell.piece->name == "King") {
                return cell.piece;
            }
        }
    }
    return nullptr;
}

// Check if the king is in check
bool Board::isKingInCheck(bool isWhiteKing, const vector<vector<Boardcell>>& board) {
    Piece* king = findKing(isWhiteKing, board);
    if(king == nullptr) return false;
    
    int kingCol = king->position.first[0] - 'a';
    int kingRow = king->position.second - 1;
    
    // Check all opponent pieces to see if they attack the king
    for(const auto& row : board) {
        for(const auto& cell : row) {
            if(!cell.isEmpty && cell.piece->isWhite != isWhiteKing) {
                // Check if this opponent piece can attack the king's position
                for(const auto& move : cell.piece->possibleMoves) {
                    if(move == king->position) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Detect if a specific piece is pinned
bool Board::isPiecePinned(Piece* piece, const vector<vector<Boardcell>>& board) {
    if(piece == nullptr || piece->name == "King") return false;
    
    Piece* king = findKing(piece->isWhite, board);
    if(king == nullptr) return false;
    
    int pieceCol = piece->position.first[0] - 'a';
    int pieceRow = piece->position.second - 1;
    int kingCol = king->position.first[0] - 'a';
    int kingRow = king->position.second - 1;
    
    // Determine the direction from piece to king
    int colDiff = 0, rowDiff = 0;
    
    if(kingCol == pieceCol) {
        colDiff = 0;
        rowDiff = (kingRow > pieceRow) ? 1 : -1;
    } else if(kingRow == pieceRow) {
        colDiff = (kingCol > pieceCol) ? 1 : -1;
        rowDiff = 0;
    } else if(abs(kingCol - pieceCol) == abs(kingRow - pieceRow)) {
        colDiff = (kingCol > pieceCol) ? 1 : -1;
        rowDiff = (kingRow > pieceRow) ? 1 : -1;
    } else {
        return false; // Piece and king are not aligned
    }
    
    // Look beyond the piece towards the king
    int checkCol = pieceCol + colDiff;
    int checkRow = pieceRow + rowDiff;
    
    while(checkCol != kingCol || checkRow != kingRow) {
        cout<<"checkRow for piece: "<<checkRow << " " <<checkCol << " " << piece->abrvName<<endl; 
        if(board[checkRow][checkCol].piece != nullptr) {
            return false; // Blocked by another piece
        }
        checkCol += colDiff;
        checkRow += rowDiff;
    }
    
    // Look in the opposite direction from the piece (away from king)
    checkCol = pieceCol - colDiff;
    checkRow = pieceRow - rowDiff;
    
    while(checkCol >= 0 && checkCol < 8 && checkRow >= 0 && checkRow < 8) {
        Piece* p = board[checkRow][checkCol].piece;
        if(p != nullptr) {
            // Found a piece - check if it's an attacking piece
            if(p->isWhite != piece->isWhite) {
                // Check if this piece can attack along this line
                string pName = p->name;
                bool canAttackOnLine = false;
                
                if(colDiff == 0 && rowDiff != 0) {
                    // Vertical line - rook or queen
                    canAttackOnLine = (pName == "Rook" || pName == "Queen");
                } else if(colDiff != 0 && rowDiff == 0) {
                    // Horizontal line - rook or queen
                    canAttackOnLine = (pName == "Rook" || pName == "Queen");
                } else if(abs(colDiff) == 1 && abs(rowDiff) == 1) {
                    // Diagonal line - bishop or queen
                    canAttackOnLine = (pName == "Bishop" || pName == "Queen");
                    
                    // Special case for pawns on diagonals
                    if(pName == "Pawn") {
                        // Check pawn attack direction
                        int pawnDirection = p->isWhite ? 1 : -1;
                        if(rowDiff == pawnDirection && abs(colDiff) == 1) {
                            canAttackOnLine = true;
                        }
                    }
                }
                
                if(canAttackOnLine) {
                    return true; // Found attacking piece - piece is pinned
                }
            }
            break; // No more pieces in this direction
        }
        checkCol -= colDiff;
        checkRow -= rowDiff;
    }
    
    return false; // Not pinned
}

// Get the pin direction (useful for restricting pinned piece movement)
pair<string, int> Board::getPinDirection(Piece* piece, const vector<vector<Boardcell>>& board) {
    if(piece == nullptr || piece->name == "King" || !isPiecePinned(piece, board)) {
        return make_pair("none", 0);
    }
    
    Piece* king = findKing(piece->isWhite, board);
    int pieceCol = piece->position.first[0] - 'a';
    int pieceRow = piece->position.second - 1;
    int kingCol = king->position.first[0] - 'a';
    int kingRow = king->position.second - 1;
    
    if(kingCol == pieceCol && kingRow != pieceRow) {
        return make_pair("vertical", kingRow > pieceRow ? 1 : -1);
    } else if(kingRow == pieceRow && kingCol != pieceCol) {
        return make_pair("horizontal", kingCol > pieceCol ? 1 : -1);
    } else if(abs(kingCol - pieceCol) == abs(kingRow - pieceRow)) {
        int colDir = kingCol > pieceCol ? 1 : -1;
        int rowDir = kingRow > pieceRow ? 1 : -1;
        return make_pair("diagonal", (colDir * 10 + rowDir));
    }
    
    return make_pair("unknown", 0);
}

// Filter moves for a pinned piece
vector<pair<string, int>> Board::filterMovesForPin(Piece* piece, const vector<pair<string, int>>& moves, const vector<vector<Boardcell>>& board) {
    vector<pair<string, int>> filteredMoves;
    
    if(!isPiecePinned(piece, board)) {
        return moves; // Not pinned, all moves are valid
    }
    
    Piece* king = findKing(piece->isWhite, board);
    int kingCol = king->position.first[0] - 'a';
    int kingRow = king->position.second - 1;
    int pieceCol = piece->position.first[0] - 'a';
    int pieceRow = piece->position.second - 1;
    
    // Determine pin direction
    int colDiff = 0, rowDiff = 0;
    if(kingCol == pieceCol) {
        rowDiff = (kingRow > pieceRow) ? 1 : -1;
    } else if(kingRow == pieceRow) {
        colDiff = (kingCol > pieceCol) ? 1 : -1;
    } else {
        colDiff = (kingCol > pieceCol) ? 1 : -1;
        rowDiff = (kingRow > pieceRow) ? 1 : -1;
    }
    
    // Only allow moves along the pin line
    for(const auto& move : moves) {
        int moveCol = move.first[0] - 'a';
        int moveRow = move.second - 1;
        
        // Check if move is along the pin line (towards or away from king)
        int moveColDiff = 0, moveRowDiff = 0;
        
        if(moveCol == pieceCol && moveRow != pieceRow) {
            moveRowDiff = (moveRow > pieceRow) ? 1 : -1;
        } else if(moveRow == pieceRow && moveCol != pieceCol) {
            moveColDiff = (moveCol > pieceCol) ? 1 : -1;
        } else if(moveCol != pieceCol && moveRow != pieceRow && 
                  abs(moveCol - pieceCol) == abs(moveRow - pieceRow)) {
            moveColDiff = (moveCol > pieceCol) ? 1 : -1;
            moveRowDiff = (moveRow > pieceRow) ? 1 : -1;
        }
        
        // Valid move if it's along the pin line or on the king line
        if((moveColDiff == colDiff && moveRowDiff == rowDiff) ||
           (moveColDiff == -colDiff && moveRowDiff == -rowDiff) ||
           (moveCol == kingCol && moveRow == kingRow && colDiff == 0 && rowDiff != 0) ||
           (moveCol == kingCol && kingRow == pieceRow && moveRow == kingRow && colDiff != 0)) {
            filteredMoves.push_back(move);
        }
    }
    
    return filteredMoves;
}

vector<pair<string, int>> Board::kingCheckPath(const vector<vector<Boardcell>>& board) {
    vector<pair<string, int>> checkPath;
    Piece* king = findKing(isWhiteTurn, board);
    if(king == nullptr) return checkPath;
    int kingCol = king->position.first[0] - 'a';
    int kingRow = king->position.second - 1;
    int attackingPieceCol,attackingPieceRow;

    for(auto& row:board)
        for(auto& cell:row)
            if(!cell.isEmpty && cell.piece->isWhite != isWhiteTurn)
                for(auto& move: cell.piece->possibleMoves)
                    if(move == king->position){
                        attackingPieceCol = cell.piece->position.first[0] - 'a';
                        attackingPieceRow = cell.piece->position.second - 1;

                        // Compute deltas from attacker to king
                        int differenceCol = kingCol - attackingPieceCol;
                        int differenceRow = kingRow - attackingPieceRow;

                        // Always include the attacker's square first
                        checkPath.push_back({ string(1, char('a' + attackingPieceCol)), attackingPieceRow + 1 });

                        
                        if (cell.piece->name == "Knight" || cell.piece->name == "Pawn") {
                            return checkPath;
                        }

                        // Compute step direction (sign of delta)
                        int colDirection = (differenceCol == 0) ? 0 : (differenceCol > 0 ? 1 : -1);
                        int rowDirection = (differenceRow == 0) ? 0 : (differenceRow > 0 ? 1 : -1);

                        int currentCol = attackingPieceCol + colDirection;
                        int currentRow = attackingPieceRow + rowDirection;

                        while(currentCol != kingCol || currentRow != kingRow) {
                            checkPath.push_back({ string(1, char('a' + currentCol)), currentRow + 1 });
                            currentCol += colDirection;
                            currentRow += rowDirection;
                        }

                        return checkPath;
                    }
    
    return checkPath; // No checking piece found
}
vector<pair<string, int>> Board::filterMovesForCheck(Piece* piece, const vector<pair<string, int>>& validMoves, const vector<vector<Boardcell>>& board) {
    vector<pair<string, int>> filteredMoves;
    for(auto& move : piece->possibleMoves) {
        // cout<<"cur move to be checked : " << move.first << move.second << endl;
        if(find(validMoves.begin(),validMoves.end(), move) != validMoves.end()) {
            // cout<<"move found" << endl;
            filteredMoves.push_back(move);
        }
    }
    return filteredMoves;
}

// Check if a move would expose the king to check. this is one of the implementations of checking whether a piece is pinned or not, yet i decided on the other implementation
// beacuse it also shows the moves of the pinned piece that are valid to move

bool Board::wouldMoveExposeKing(Piece* piece, const pair<string, int>& movePos, const vector<vector<Boardcell>>& board) {
    if(piece == nullptr) return true;
    
    // Create a temporary board state
    vector<vector<Boardcell>> tempBoard = board;
    
    // Make the move
    int startCol = piece->position.first[0] - 'a';
    int startRow = piece->position.second - 1;
    int endCol = movePos.first[0] - 'a';
    int endRow = movePos.second - 1;
    
    tempBoard[endRow][endCol].assignPiece(piece);
    tempBoard[startRow][startCol].removePiece();
    
    // Update piece's temporary position
    auto originalPos = piece->position;
    piece->position = movePos;
    
    // Check if king is in check after the move
    bool kingInCheck = isKingInCheck(piece->isWhite, tempBoard);
    
    // Restore original position
    piece->position = originalPos;
    
    return kingInCheck;
}

bool Board::isCheckmate(bool isWhiteKing, const vector<vector<Boardcell>>& board){
    Piece* checkedKing = findKing(isWhiteKing,board);
    if(checkedKing->possibleMoves.empty()){
        for(auto& piece : pieces)
            if(piece->isWhite == isWhiteKing && !piece->possibleMoves.empty() && piece->name != "King"){
                cout<< piece->abrvName << " has moves still" <<endl; 
                return false;
            }
        return true;
    }
    return false;
}
void Board::resetEverything(){
    pieces.clear();
    whitePieces->pieces.clear();
    blackPieces->pieces.clear();
    boardCells.clear();
    isWhiteTurn = true;
    isCheck = false;
    isGameOver = false;
}
Board::~Board() {
}
