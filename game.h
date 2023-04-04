#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "player.h"
#include "boardPiece.h"
#include "ownableProperty.h"
#include "subject.h"

class TextDisplay;

class Game{
    protected:
        const int minPlayers = 6;
        const int maxPlayers = 8;
        const int pieces = 40;
        const int initialMoney = 1500;

        int numPlayers; 
        std::vector<Player *> order;
        std::vector<BoardPiece *> game;
        
        bool testing = false;

    public:
        Game();     // Constructor initializer
        void start();   // starts the game
        int getNumPlayers();
        int getPieces();
        bool getTesting();
        bool setTesting();
        std::vector<BoardPiece *> getGame();

        int roll(Player * p);
        void next(Player * p);
        void trade(Player * p);
        void buyImprovement(Player * p);
        void sellImprovement(Player * p);
        void mortgage(Player * p);
        void unmortgage(Player * p);
        void bankrupt(Player * p);
        void assets(Player * p);
        void all();
        void save(std::string file);
        void load(std::string file);
        void auction();
};

#endif
