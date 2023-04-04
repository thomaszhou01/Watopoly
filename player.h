#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class BoardPiece;

class Player{
    
    const std::string name;
    const char character;
    int position;
    int money;
    bool bankrupt;
    bool inTims;
    int turnsInTims;
    int rollUpTheRimCards;
    std::vector<BoardPiece*> properties;

    public:
        static int rollupCardsGiven;
        Player(std::string name, char character);
        std::string getName();
        char getCharacter();
        int getPosition();
        int getMoney();
        bool isBankrupt();
        void setBankrupt(Player* p);
        bool isInTims();
        void reduceTimsTime();
        void sendToTims();
        int getRollUpTheRimCards();
        void setRollUpTheRimCards(int number);
        void addMoney(int newMoney);
        void subtractMoney(int newMoney);
        void addProperty(BoardPiece* bp);
        void removeProperty(BoardPiece* bp);
        std::vector<BoardPiece*> getProperties();
        bool trade(Player* p, std::string give, std::string recieve);
        void setPosition(int pos);
        void showAssets();
};

#endif
