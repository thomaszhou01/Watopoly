#ifndef OWNABLEPROPERTY_H
#define OWNABLEPROPERTY_H
#include "boardPiece.h"

class OwnableProperty: public BoardPiece{
    
    public:
        OwnableProperty(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position);
        void morgage(Player* p) override;
        void unmorgage(Player* p) override;
        void improve(Player* p) override;        
        void landedOn(Player* p) override;

};

#endif
