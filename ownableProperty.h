#ifndef OWNABLEPROPERTY_H
#define OWNABLEPROPERTY_H
#include "boardPiece.h"

class OwnableProperty: public BoardPiece{
    int calculateTuition();
    public:
        OwnableProperty(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet, int row, int col);
        bool mortgage(Player* p) override;
        bool unmortgage(Player* p) override;
        bool improve(Player* p) override;   
        bool sellImprovement(Player* p) override;
        void landedOn(Player* p) override;
};

#endif
