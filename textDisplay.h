#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <memory>
#include "observer.h"
#include "player.h"
#include "boardPiece.h"
#include "game.h"
#include "subject.h"

class TextDisplay: public Observer{
    protected:
        Game * game;    // whole game which includes all board pieces
        std::vector<std::shared_ptr<Player>> players;    // indicates which player is in which board piece
        char board[56][89];
        void updateBoardPiece(BoardPiece * piece); // updates the allocated board pieces
    public:
        TextDisplay(Game * game, std::vector<std::shared_ptr<Player>> players);   // Constructor
        virtual void notify(Subject * subject) override; // BoardPiece notifies the TextDisplay class to make changes 
        void display(); // outputs the board
};

#endif
