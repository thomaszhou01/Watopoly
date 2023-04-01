#ifndef OWNABLEPROPERTY_H
#define OWNABLEPROPERTY_H
#include "boardPiece.h"

class OwnableProperty: public BoardPiece{
    
    int calculateTuition();
    public:
        OwnableProperty(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position);
        void mortgage(Player* p) override;
        void unmortgage(Player* p) override;
        void improve(Player* p) override;        
        void landedOn(Player* p) override;

};

#endif
