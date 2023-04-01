#include "boardPiece.h"

bool BoardPiece::isOwnable(){
    return isOwnable;
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

int BoardPiece::getPosition(){
    return position;
}

int BoardPiece::getPrice(){
    return cost;
}

bool BoardPiece::tuitionPaid(){
    return tuitionPaid;
}

bool BoardPiece::isMortgaged(){
    return isMortgaged;
}

std::string BoardPiece::getName(){
    return name;
}

std::string BoardPiece::getId(){
    return id;
}
