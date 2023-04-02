#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "boardPiece.h"
#include "subject.h"
#include "string"

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

        BoardPiece(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet, bool ownable);
        BoardPiece * CollectOsap{"Collect Osap", "COLLECTOSAP", -1, -1, {}, 0, false, false, 0, false};
        BoardPiece * AL{"AL", "AL", 40, 50, {2, 10, 30, 90, 160, 250}, 1, false, false, 2, true};
        BoardPiece * SLC{"SLC", "SLC", -1, -1, {}, 2, false, false, 0, false};
        //BoardPiece * 


    public:
        void start();   // starts the game, no constructor required
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
