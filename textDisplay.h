#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include "observer.h"
#include "player.h"
#include "boardPiece.h"
#include "game.h"

class TextDisplay: public Observer{
    protected:
        Game * game;    // whole game which includes all board pieces
        std::vector<Player *> players;    // indicates which player is in which board piece
        void updateGame(Game * game, int row, int col); // updates the allocated board pieces
    public:
        TextDisplay(Game * game, std::vector<Player*> players);   // Constructor
        virtual void notify() override; // BoardPiece notifies the TextDisplay class to make changes 
        void display(); // outputs the board
        ~TextDisplay() override;    // Destructor
};

#endif
