#ifndef BOARDPIECE_H
#define BOARDPIECE_H
#include "subject.h"
#include "player.h"

class BoardPiece: public Subject{
    protected:
        const int position;
        const std::string name;
        const std::string id;
        const int cost;
        const int improvementCost;
        const std::vector<int> tuition;
        const bool gym;
        const bool residence;
        int improvementTier;
        int propertiesInSet;
        Player *ownedPlayer;
        bool owned;
        bool mortgaged;
        bool ownable;
        bool tuitionPaid;
    public:
        BoardPiece(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet, bool ownable);
        bool isOwnable(); //gets if it is an ownable property or unownable
        bool isOwned(); //gets if it is owned 
        Player* getOwner();
        bool isGym();
        bool isResidence();
        int getPosition();
        int getPrice();
        int getPropertiesInSet();
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
