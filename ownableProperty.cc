#include "ownableProperty.h"

void OwnableProperty::mortgage(Player* p){
    if(!isMortgaged && improvementTier == 0 && p == ownedPlayer){
        int morgageMoney = cost/2;
        //money gets added to player
        mortgaged = true;
    }
}

void OwnableProperty::unmortgage(Player* p){
    if(isMortgaged && p == ownedPlayer){
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
