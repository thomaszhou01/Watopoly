#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <memory>
#include "observer.h"
#include "player.h"
#include "boardPiece.h"
#include "subject.h"
class Game;


class TextDisplay: public Observer{
    protected:
        Game * game;    // whole game which includes all board pieces
        std::vector<std::shared_ptr<Player>> players;    // indicates which player is in which board piece
        char board[56][89];
        void updateBoardPiece(BoardPiece * piece); // updates the allocated board pieces
    public:
        TextDisplay(Game * game);   // Constructor
        virtual void notify(Subject * subject) override; // BoardPiece notifies the TextDisplay class to make changes 
        void display(); // outputs the board
};

#endif
