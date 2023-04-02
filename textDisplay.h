#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include "vector"
#include "player.h"
#include "boardPiece.h"
#include "game.h"

class TextDisplay: public Observer{
    protected:
        Game * game;
        std::vector<Player> players;
        void updateGame(Game * game, int row, int col);
    public:
        TextDisplay(BoardPiece * piece);
        virtual void notify(Subject * subject) override;
        void display();

};

#endif
