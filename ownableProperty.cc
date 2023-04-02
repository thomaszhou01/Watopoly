#include "ownableProperty.h"


OwnableProperty::OwnableProperty(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet): 
    BoardPiece{name, id, cost, improvementCost, tuition, position, isGym, isResidence, propertiesInSet, true}{}

void OwnableProperty::mortgage(Player* p){
    if(!mortgaged && improvementTier == 0 && p == ownedPlayer){
        int morgageMoney = cost/2;
        //money gets added to player
        mortgaged = true;
    }
}

void OwnableProperty::unmortgage(Player* p){
    if(mortgaged && p == ownedPlayer){
        int morgageMoney = cost*0.6;
        //player gets money withdrawed
        mortgaged = false;
    }
}

void OwnableProperty::improve(Player* p){
    // std::vector<BoardPiece*> = p->getProperties();
    

}

void OwnableProperty::landedOn(Player* p){
    
}

OwnableProperty::~OwnableProperty(){
    
}
