#ifndef BOARDPIECE_H
#define BOARDPIECE_H
#include <iostream>
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
        const bool ownable;
        const int propertiesInSet;
        int improvementTier;
        Player *ownedPlayer;
        bool owned;
        bool mortgaged;
        bool tuitionPaid;
        // what is propertiesInSet? is that the amount of Buildings in a Monopoly Block?
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
        bool isTuitionPaid();
        bool isMortgaged();
        std::string getName();
        std::string getId();
        virtual bool mortgage(Player* p);
        virtual bool unmortgage(Player* p);
        virtual bool improve(Player* p);
        virtual bool sellImprovement(Player* p);
        virtual void landedOn(Player* p) = 0;
        virtual ~BoardPiece()=0;

};

#endif
