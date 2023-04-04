#include "boardPiece.h"

BoardPiece::BoardPiece(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool gym, bool residence, int propertiesInSet, bool ownable, int row, int col):
    name{name}, id{id}, cost{cost}, improvementCost{improvementCost}, tuition{tuition}, position{position}, gym{gym}, residence{residence}, propertiesInSet{propertiesInSet}, ownable{ownable}, improvementTier{0}, ownedPlayer{nullptr}, owned{false}, mortgaged{false}, tuitionPaid{true}, row{row}, col{col}{}

bool BoardPiece::isOwnable(){
    return ownable;
}

bool BoardPiece::isOwned(){
    return owned;
}

Player* BoardPiece::getOwner(){
    return ownedPlayer;
}

void BoardPiece::setOwner(Player* p){
    ownedPlayer = p;
}

bool BoardPiece::isGym(){
    return gym;
}

bool BoardPiece::isResidence(){
    return residence;
}

int BoardPiece::getPosition(){
    return position;
}

int BoardPiece::getPrice(){
    return cost;
}

int BoardPiece::getPropertiesInSet(){
    return propertiesInSet;
}

int BoardPiece::getImprovementCost(){
    return improvementCost;
}

int BoardPiece::getImprovementLevel(){
    return improvementTier;
}

bool BoardPiece::isTuitionPaid(){
    return tuitionPaid;
}

bool BoardPiece::isMortgaged(){
    return mortgaged;
}

std::string BoardPiece::getName(){
    return name;
}

std::string BoardPiece::getId(){
    return id;
}

void BoardPiece::reset(){
    ownedPlayer = nullptr;
    mortgaged = false;
    improvementTier = 0;
    owned = false;
}

bool BoardPiece::mortgage(Player* p){}
bool BoardPiece::unmortgage(Player* p){}
bool BoardPiece::improve(Player* p){}
bool BoardPiece::sellImprovement(Player* p){}
BoardPiece::~BoardPiece(){}

int BoardPiece::getRow(){
    return row;
}

int BoardPiece::getCol(){
    return col;
}
