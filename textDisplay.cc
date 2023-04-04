#include "textDisplay.h"
#include <fstream>
using namespace std;

// we have to update a boardPiece if it is owned(O), improved(I), and mortgaged(M) 
void TextDisplay::updateBoardPiece(BoardPiece * piece) {
    int row = piece->getRow();
    int col = piece->getCol();

    if (piece->getOwner() != nullptr) {
        board[row][col] = 'O';
        board[row + 3][col] = piece->getOwner()->getCharacter();
    }

    if (piece->isMortgaged() == true) {
        board[row][col+1] = 'M';
        board[row][col+2] = ' ';
        board[row][col+3] = ' ';
        board[row][col+4] = ' ';
        board[row][col+5] = ' ';
        board[row][col+6] = ' ';
    }

    if (piece->getImprovementLevel() == 1) {
        board[row][col+2] = 'I';
    } else if (piece->getImprovementLevel() == 2) {
        board[row][col+2] = 'I';
        board[row][col+3] = 'I';
    } else if (piece->getImprovementLevel() == 3) {
        board[row][col+2] = 'I';
        board[row][col+3] = 'I';
        board[row][col+4] = 'I';
    } else if (piece->getImprovementLevel() == 4) {
        board[row][col+2] = 'I';
        board[row][col+3] = 'I';
        board[row][col+4] = 'I';
        board[row][col+5] = 'I';
    } else if (piece->getImprovementLevel() == 5) {
        board[row][col+2] = 'I';
        board[row][col+3] = 'I';
        board[row][col+4] = 'I';
        board[row][col+5] = 'I';
        board[row][col+6] = 'I';
    }

    int playerNum = 0;
    for (int i = 0; i < game->getNumPlayers(); ++i) {
        if (players[i]->getPosition() == piece->getPosition()) {
            if (playerNum < 4) {
                board[row+1][col+3+playerNum] = players[i]->getCharacter();
            } else {
                board[row+2][col+playerNum-1] = players[i]->getCharacter();
            }
        } else {
            if (playerNum < 4) {
                board[row+1][col+3+playerNum] = ' ';
            } else {
                board[row+2][col+playerNum-1] = ' ';
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
        for (int i = 0; i < s.length(); ++i) {
            board[row][i] = s[i];
        }
        ++row;
    }
}

void TextDisplay::notify(Subject * subject) {
    BoardPiece * piece = nullptr;
    for (int i = 0; i < game->getPieces(); i++) {
        if (game->getGame()[i]->getName() == subject->getName()) {
            piece = game->getGame()[i];
            break;
        }
    }
    updateBoardPiece(piece);
}

void TextDisplay::display() {
    for (int i = 0; i < 55; ++i) {
        for (int j = 0; j < 88; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

TextDisplay::~TextDisplay(){}
