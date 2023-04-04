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
        const int row;
        const int col;
    public:
        BoardPiece(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet, bool ownable, int row, int col);
        bool isOwnable(); //gets if it is an ownable property or unownable
        bool isOwned(); //gets if it is owned 
        Player* getOwner();
        void setOwner(Player* p);
        bool isGym();
        bool isResidence();
        int getPosition();
        int getPrice();
        int getPropertiesInSet();
        int getImprovementCost();
        int getImprovementLevel();
        bool isTuitionPaid();
        bool isMortgaged();
        std::string getName() override;
        std::string getId();
        void reset();
        virtual bool mortgage(Player* p);
        virtual bool unmortgage(Player* p);
        virtual bool improve(Player* p);
        virtual bool sellImprovement(Player* p);
        virtual void landedOn(Player* p)=0;
        virtual ~BoardPiece()=0;

        int getRow();
        int getCol();

};

#endif
