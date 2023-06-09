#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include <memory>
#include "player.h"
#include "boardPiece.h"
#include "subject.h"
#include "textDisplay.h"

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
        std::vector<std::shared_ptr<Player>> order;
        std::vector<int> orderIndex;
        std::vector<std::shared_ptr<BoardPiece>> game;
        TextDisplay textDisplay;
        bool playerCharTaken[8] = {false, false, false, false, false, false, false, false};
        int consecutiveDoubles[8] = {0,0,0,0,0,0,0,0};
        
        
        std::vector<int> testRoll(int die1, int die2);
        std::vector<int> rollDie();
        void rollLogic(std::vector<int>& roll, bool& hasRolled, bool& rolledDouble, int& playerIndex, bool& over);
        void makeMoney(int& playerIndex, int& newPos, bool& over, bool& hasRolled);
        void commands(Player * p);
        void auction(BoardPiece * b, int playerThatStartedAuction);
    public:
        Game();     // Constructor initializer
        void InitializeOrder();
        void start();   // starts the game
        int getNumPlayers();
        int getPieces();
        bool getTesting();
        void setTesting();
        std::vector<std::shared_ptr<Player>> getOrder();
        std::vector<std::shared_ptr<BoardPiece>> getGame();

        void save(std::string file);
        void load(std::string file);
};

#endif
