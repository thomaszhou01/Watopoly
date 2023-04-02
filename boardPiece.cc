#include "boardPiece.h"

BoardPiece::BoardPiece(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool gym, bool residence, int propertiesInSet, bool ownable):
    name{name}, id{id}, cost{cost}, improvementCost{improvementCost}, tuition{tuition}, position{position}, gym{gym}, residence{residence}, propertiesInSet{propertiesInSet}, ownable{ownable}, improvementTier{0}, ownedPlayer{nullptr}, owned{false}, mortgaged{false}, tuitionPaid{true}{}

bool BoardPiece::isOwnable(){
    return ownable;
}

bool BoardPiece::isOwned(){
    return owned;
}

Player* BoardPiece::getOwner(){
    return ownedPlayer;
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

BoardPiece::~BoardPiece(){}
