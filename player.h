#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

class BoardPiece;

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
        void setBankrupt();
        bool isInTims();
        void sendToTims();
        int getTurnsInTims();
        void addMoney(int money);
        void subtractMoney(int money);
        void addProperty(BoardPiece* bp);
        std::vector<BoardPiece*> getProperties();
        bool trade(Player* p);
        void setPosition(int pos);
        void showAssets();
};

#endif
