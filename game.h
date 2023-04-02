#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "boardPiece.h"
#include "subject.h"

class Game{
    protected:
        const int minPlayers = 6;
        const int maxPlayers = 8;
        const int pieces = 40;
        const int initialMoney = 1500;

        int numPlayers;
        std::vector<Player *> order;
        BoardPiece * game[40];

        bool testing = false;
    public:
        void start();
        int getNumPlayers();
        bool getTesting();
        bool setTesting();

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
