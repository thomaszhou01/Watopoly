#ifndef BOARDPIECE_H
#define BOARDPIECE_H
#include "subject.h"
#include "player.h"

class BoardPiece: public Subject{
    protected:
        int position;
        std::string name;
        std::string id;
        int cost;
        int improvementCost;
        int improvementTier;
        std::vector<int> tuition;
        Player *ownedPlayer;
        bool isOwned;
        bool isMorgaged;
        bool isGym;
        bool isOwnable;
        bool tuitionPaid;
    public:
        bool isOwnable(); //gets if it is an ownable property or unownable
        Player* owned(); //gets if it is owned 
        int getPosition();
        int getPrice();
        bool tuitionPaid();
        std::string getName();
        virtual void morgage(Player* p);
        virtual void unmorgage(Player* p);
        virtual void improve(Player* p);
        virtual void landedOn(Player* p) = 0;

};

#endif
