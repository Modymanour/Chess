#include "../Headers/piecesMovement.h"

vector<pair<string, int>> movement::diagonalMove(const pair<string, int>& startPos, vector<vector<Boardcell>>& board) {
    vector<pair<string, int>> possibleMoves;
    int col = startPos.first[0] - 'a';
    int row = startPos.second - 1;
    Piece* piece = board[startPos.second - 1][startPos.first[0] - 'a'].piece;
    if(piece == nullptr) return possibleMoves;
    //down left
    col--;
    row--;
    while(col >= 0 && row >= 0) {
        if(board[row][col].isEmpty) {
            possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            board[row][col].threatenedBy.push_back(piece);
        } else {
            if(board[row][col].piece->isWhite != piece->isWhite) {
                possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            }
            board[row][col].threatenedBy.push_back(piece);//even if it is the same color piece, it should be defending that piece
            break;
        }
        col--;
        row--;
    }
    col = startPos.first[0] - 'a';
    row = startPos.second - 1;
    //down right
    col++;
    row--;
    while(col < 8 && row >= 0) {
        if(board[row][col].isEmpty) {
            possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            board[row][col].threatenedBy.push_back(piece);
        } else {
            if(board[row][col].piece->isWhite != piece->isWhite) {
                possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            }
            board[row][col].threatenedBy.push_back(piece);
            break;
        }
        col++;
        row--;
    }
    col = startPos.first[0] - 'a';
    row = startPos.second - 1;
    //up left
    col--;
    row++;
    while(col >= 0 && row < 8) {
        if(board[row][col].isEmpty) {
            possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            board[row][col].threatenedBy.push_back(piece);
        } else {
            if(board[row][col].piece->isWhite != piece->isWhite) {
                possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            }
            board[row][col].threatenedBy.push_back(piece);
            break;
        }
        col--;
        row++;
    }
    col = startPos.first[0] - 'a';
    row = startPos.second - 1;
    //up right
    col++;
    row++;
    while(col < 8 && row < 8) {
        if(board[row][col].isEmpty) {
            possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            board[row][col].threatenedBy.push_back(piece);
        } else {
            if(board[row][col].piece->isWhite != piece->isWhite) {
                possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            }
            board[row][col].threatenedBy.push_back(piece);
            break;
        }
        col++;
        row++;
    }
    return possibleMoves;
}

vector<pair<string, int>> movement::horizontalMove(const pair<string, int>& startPos, vector<vector<Boardcell>>& board) {
    vector<pair<string, int>> possibleMoves;
    int col = startPos.first[0] - 'a';
    int row = startPos.second - 1;
    Piece* piece = board[startPos.second - 1][startPos.first[0] - 'a'].piece;
    if(piece == nullptr) return possibleMoves;
    //left
    col--;
    while(col >= 0) {
        // cout<< "Checking horizontal left at " << string(1, col + 'a') << row + 1 <<"for " << piece->abrvName << endl;
        if(board[row][col].isEmpty) {
            possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            board[row][col].threatenedBy.push_back(piece);
        } else {
            if(board[row][col].piece->isWhite != piece->isWhite) {
                possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            }
            board[row][col].threatenedBy.push_back(piece);
            break;
        }
        col--;
    }
    col = startPos.first[0] - 'a';
    //right
    col++;
    while(col < 8) {
        // cout<< "Checking horizontal right at " << string(1, col + 'a') << row + 1 <<"for " << piece->abrvName << endl;
        if(board[row][col].isEmpty) {
            possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            board[row][col].threatenedBy.push_back(piece);
        } else {
            if(board[row][col].piece->isWhite != piece->isWhite) {
                possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            }
            board[row][col].threatenedBy.push_back(piece);
            break;
        }
        col++;
    }
    return possibleMoves;
}
vector<pair<string, int>> movement::verticalMove(const pair<string, int>& startPos, vector<vector<Boardcell>>& board) {
    vector<pair<string, int>> possibleMoves;
    int col = startPos.first[0] - 'a';
    int row = startPos.second - 1;
    Piece* piece = board[startPos.second - 1][startPos.first[0] - 'a'].piece;
    if(piece == nullptr) return possibleMoves;
    //down
    row--;
    while(row >= 0) {
        // cout<< "Checking vertical down at " << string(1, col + 'a') << row + 1 <<"for " << piece->abrvName << endl;
        if(board[row][col].isEmpty) {
            possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            board[row][col].threatenedBy.push_back(piece);
        } else {
            if(board[row][col].piece->isWhite != piece->isWhite) {
                possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            }
            board[row][col].threatenedBy.push_back(piece);
            break;
        }
        row--;
    }
    row = startPos.second - 1;
    row++;
    //up
    while(row < 8) {
        // cout<< "Checking vertical up at " << string(1, col + 'a') << row + 1 <<"for " << piece->abrvName << endl;
        if(board[row][col].isEmpty) {
            // cout << "Adding vertical up move " << string(1, col + 'a') << row + 1 <<"for " << piece->abrvName << endl;
            possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            board[row][col].threatenedBy.push_back(piece);
        } else {
            //  cout << "Encountered piece " << board[row][col].piece->abrvName << " at " << string(1, col + 'a') << row + 1 <<" for " << piece->abrvName << endl;
            if(board[row][col].piece->isWhite != piece->isWhite) {
                    // cout << "Adding vertical up capture move " << string(1, col + 'a') << row + 1 <<" for " << piece->abrvName << endl;
                possibleMoves.push_back(make_pair(string(1, col + 'a'), row + 1));
            }
            board[row][col].threatenedBy.push_back(piece);
            break;
        }
        row++;
    }
    return possibleMoves;
}
vector<pair<string, int>> movement::knightMove(const pair<string, int>& startPos, vector<vector<Boardcell>>& board) {
    vector<pair<string, int>> possibleMoves;
    int col = startPos.first[0] - 'a';
    int row = startPos.second - 1;
    Piece* piece = board[startPos.second - 1][startPos.first[0] - 'a'].piece;
    if(piece == nullptr) return possibleMoves;
    vector<pair<int, int>> knightMoves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for(auto& move : knightMoves) {
        int newRow = row + move.first;
        int newCol = col + move.second;
        if(newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if(board[newRow][newCol].isEmpty || board[newRow][newCol].piece->isWhite != piece->isWhite) {
                possibleMoves.push_back(make_pair(string(1, newCol + 'a'), newRow + 1));
            }
            board[newRow][newCol].threatenedBy.push_back(piece);
        }
    }
    return possibleMoves;
}
vector<pair<string, int>> movement::kingMove(const pair<string, int>& startPos, vector<vector<Boardcell>>& board) {
    vector<pair<string, int>> possibleMoves;
    int col = startPos.first[0] - 'a';
    int row = startPos.second - 1;
    Piece* piece = board[startPos.second - 1][startPos.first[0] - 'a'].piece;
    if(piece == nullptr) return possibleMoves;
    vector<pair<int, int>> kingMoves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for(auto& move : kingMoves) {
        int newRow = row + move.first;
        int newCol = col + move.second;
        if(newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if((board[newRow][newCol].isEmpty || board[newRow][newCol].piece->isWhite != piece->isWhite) && !board[newRow][newCol].isThreatenedByOpponent(piece->isWhite)) {
                possibleMoves.push_back(make_pair(string(1, newCol + 'a'), newRow + 1));
            }
            board[newRow][newCol].threatenedBy.push_back(piece);
        }
    }
    return possibleMoves;
}
vector<pair<string,int>> movement::pawnMove(const pair<string, int>& startPos, vector<vector<Boardcell>>& board) {
    vector<pair<string,int>> possibleMoves;
    Piece* piece = board[startPos.second - 1][startPos.first[0] - 'a'].piece;
    if(piece == nullptr) return possibleMoves;
    string col = startPos.first;
    int row = startPos.second - 1;
    int direction = piece->isWhite ? 1 : -1; //white moves up, black moves down

    int forwardRow = row + direction;
    // forward one
    if(forwardRow >= 0 && forwardRow < 8) {
        if(board[forwardRow][col[0]-'a'].isEmpty) {
            possibleMoves.push_back(make_pair(col, forwardRow + 1));
            // two-square initial move
            int forward2 = row + 2*direction;
            if(!piece->hasMoved && forward2 >= 0 && forward2 < 8 && board[forward2][col[0]-'a'].isEmpty) {
                possibleMoves.push_back(make_pair(col, forward2 + 1));
            }
        }
    }

    // captures (diagonals)
    // left capture
    if(forwardRow >= 0 && forwardRow < 8 && col[0] > 'a') {
        int ccol = col[0]-'a'-1;
        if(!board[forwardRow][ccol].isEmpty && board[forwardRow][ccol].piece->isWhite != piece->isWhite) {
            possibleMoves.push_back(make_pair(string(1, col[0]-1), forwardRow + 1));
        }
        // threatened cell marking
        if(board[forwardRow][ccol].isEmpty || board[forwardRow][ccol].piece->isWhite != piece->isWhite) {
            board[forwardRow][ccol].threatenedBy.push_back(piece);
        }
    }
    // right capture
    if(forwardRow >= 0 && forwardRow < 8 && col[0] < 'h') {
        int ccol = col[0]-'a'+1;
        if(!board[forwardRow][ccol].isEmpty && board[forwardRow][ccol].piece->isWhite != piece->isWhite) {
            possibleMoves.push_back(make_pair(string(1, col[0]+1), forwardRow + 1));
        }
        if(board[forwardRow][ccol].isEmpty || board[forwardRow][ccol].piece->isWhite != piece->isWhite) {
            board[forwardRow][ccol].threatenedBy.push_back(piece);
        }
    }

    return possibleMoves;
}