#include "textDisplay.h"
#include <fstream>
using namespace std;

// we have to update a boardPiece if it is owned(O), improved(I), and mortgaged(M) 
void TextDisplay::updateBoardPiece(BoardPiece * piece) {
    int row = piece->getRow()-1;
    int col = piece->getCol()-1;

    if (piece->getOwner() != nullptr) {
        board[row+1][col+1] = 'O';
        board[row+4][col+1] = piece->getOwner()->getCharacter();
    }
    else{
        board[row+1][col+1] = ' ';
        board[row+4][col+1] = ' ';
    }

    if (piece->isMortgaged() == true) {
        board[row+1][col+2] = 'M';
        board[row+1][col+3] = ' ';
        board[row+1][col+4] = ' ';
        board[row+1][col+5] = ' ';
        board[row+1][col+6] = ' ';
        board[row+1][col+7] = ' ';
    }
    else{
        board[row+1][col+2] = ' ';
        board[row+1][col+3] = ' ';
        board[row+1][col+4] = ' ';
        board[row+1][col+5] = ' ';
        board[row+1][col+6] = ' ';
        board[row+1][col+7] = ' ';
    }

    if (piece->getImprovementLevel() == 1) {
        board[row+1][col+3] = 'I';
    } else if (piece->getImprovementLevel() == 2) {
        board[row+1][col+3] = 'I';
        board[row+1][col+4] = 'I';
    } else if (piece->getImprovementLevel() == 3) {
        board[row+1][col+3] = 'I';
        board[row+1][col+4] = 'I';
        board[row+1][col+5] = 'I';
    } else if (piece->getImprovementLevel() == 4) {
        board[row+1][col+3] = 'I';
        board[row+1][col+4] = 'I';
        board[row+1][col+5] = 'I';
        board[row+1][col+6] = 'I';
    } else if (piece->getImprovementLevel() == 5) {
        board[row+1][col+3] = 'I';
        board[row+1][col+4] = 'I';
        board[row+1][col+5] = 'I';
        board[row+1][col+6] = 'I';
        board[row+1][col+7] = 'I';
    }

    int playerNum = 0;
    for (int i = 0; i < players.size(); ++i) {
        if (players[i]->getPosition() == piece->getPosition()) {
            if (playerNum < 4) {
                board[row+3][col+7-playerNum] = players[i]->getCharacter();
            } else {
                board[row+4][col+playerNum] = players[i]->getCharacter();
            }
        } else {
            if (playerNum < 4) {
                board[row+3][col+7-playerNum] = ' ';
            } else {
                board[row+4][col+playerNum] = ' ';
            }
        }
        ++playerNum;
    }
}

// sets up board, does not update anything yet.
TextDisplay::TextDisplay(Game * game, vector<Player *> players): game{game}, players{players} {
    ifstream f("board.txt");
    string s;
    int row = 0;
    while (getline(f, s)) {
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            board[row][i] = s[i];
        }
        ++row;
    }
}

void TextDisplay::notify(Subject * subject) {
    BoardPiece * piece = nullptr;
    for (int i = 0; i < game->getPieces(); ++i) {
        if (game->getGame()[i]->getName() == subject->getName() && game->getGame()[i]->getRow() == subject->getRow() && game->getGame()[i]->getCol() == subject->getCol()) {
            piece = game->getGame()[i];
            break;
        }
    }
    updateBoardPiece(piece);
}

void TextDisplay::display() {
    for (int i = 0; i < 56; ++i) {
        for (int j = 0; j < 89; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
}
