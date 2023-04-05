#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "player.h"
#include "boardPiece.h"
#include "subject.h"

class TextDisplay;

class Game{
    protected:
        const int maxPlayers = 8;
        const int pieces = 40;
        const char playerChar[8] = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};
        int rollUpTheRimCards = 0;
        const int ownable = 28;
        const int unownable = 12;
        bool testing = false;

        int numPlayers; 
        std::vector<Player *> order;
        std::vector<BoardPiece *> game;
        TextDisplay * textDisplay;
        bool playerCharTaken[8] = {false, false, false, false, false, false, false, false};
        
        std::vector<int> testRoll(int die1, int die2);
        std::vector<int> rollDie();
        //void next(Player * p);
        //void buyImprovement(Player * p);
        //void sellImprovement(Player * p);
        //void mortgage(Player * p);
        //void unmortgage(Player * p);
        //void bankrupt(Player * p);
        //void assets(Player * p);
        //void all();
        //void auction();
        void commands(Player * p);
    public:
        Game();     // Constructor initializer
        ~Game();
        void InitializeOrder();
        void start();   // starts the game
        int getNumPlayers();
        int getPieces();
        bool getTesting();
        void setTesting();
        std::vector<Player *> getOrder();
        std::vector<BoardPiece *> getGame();

        void save(std::string file, int playerOrderIndex);
        void load(std::string file);
};

#endif
