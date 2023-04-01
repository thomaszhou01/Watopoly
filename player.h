#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <boardPiece.h>

class Player{
    const std::string name;
    const char character;
    int position;
    int money;
    bool bankrupt;
    bool inTims;
    int turnsInTims;
    std::vector<BoardPiece*> properties;

    public:
        std::string getName();
        int getPosition();
        int getMoney();
        bool isBankrupt();
        void bankrupt();
        bool inTims();
        void sendToTims();
        int turnsInTims();
        void addMoney(int money);
        void addProperty(BoardPiece* bp);
        bool trade(Player* p);
        void setPosition(int pos);
        void showAssets();
};

#endif
