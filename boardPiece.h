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
        Player *ownedPlayer = nullptr;
        bool owned;
        bool mortgaged;
        bool gym;
        bool ownable;
        bool tuitionPaid;
    public:
        bool isOwnable(); //gets if it is an ownable property or unownable
        bool isOwned(); //gets if it is owned 
        Player* getOwner();
        bool isGym();
        int getPosition();
        int getPrice();
        bool tuitionPaid();
        bool isMortgaged();
        std::string getName();
        std::string getId();
        virtual void mortgage(Player* p);
        virtual void unmortgage(Player* p);
        virtual void improve(Player* p);
        virtual void landedOn(Player* p) = 0;

};

#endif
