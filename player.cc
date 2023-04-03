#include "player.h"
#include "boardPiece.h"

int Player::rollupCardsGiven = 0;

Player::Player(std::string name, char character): name{name}, character{character}{}

std::string Player::getName(){
    return name;
}

int Player::getPosition(){
    return position;
}

int Player::getMoney(){
    return money;
}

bool Player::isBankrupt(){
    return bankrupt;
}

//argument is the Player they got bankrupt from
void Player::setBankrupt(Player* p){
    if(p != nullptr){
        p->addMoney(this->money);
        for(auto & i : this->properties){
            i->setOwner(p);
            p->addProperty(i);
        }
        p->setRollUpTheRimCards(p->getRollUpTheRimCards() + rollUpTheRimCards);
    }
    else{
        for(auto & i : this->properties){
            i->reset();
        }
    }

    bankrupt = true;
}

bool Player::isInTims(){
    return inTims;
}

void Player::reduceTimsTime(){
    turnsInTims = turnsInTims-1;
}

void Player::sendToTims(){
    position = 10;
    inTims = true;
    turnsInTims = 3;
}

int Player::getRollUpTheRimCards(){
    return rollUpTheRimCards;
}

void Player::setRollUpTheRimCards(int number){
    rollUpTheRimCards = number;
}

void Player::addMoney(int newMoney){
    money += newMoney;
}

void Player::subtractMoney(int newMoney){
    money -= newMoney;
}

void Player::addProperty(BoardPiece* bp){
    properties.push_back(bp);
}

void Player::removeProperty(BoardPiece* bp){
    std::vector<BoardPiece*> temp;
    for(auto & i : this->properties){
        if(i != bp){
            temp.push_back(i);
        }
    }
    properties = temp;
}

std::vector<BoardPiece*> Player::getProperties(){
    return properties;
}

bool Player::trade(Player* p, std::string give, std::string recieve){
    int giveInt;
    int recieveInt;
    std::istringstream giveTransform{give};
    std::istringstream recieveTransform{recieve};
    giveTransform >> giveInt;
    recieveTransform >> recieveInt;

    bool hasGive = false;
    bool hasRecieve = false;
    BoardPiece* giveProperty = nullptr;
    BoardPiece* recieveProperty = nullptr;

    //check if player has the property to give
    if(!giveTransform){
        for(auto & i : this->properties){
            if(i->getId() == give){
                hasGive = true;
                giveProperty = i;
                break;
            }
        }
        if(!hasGive){
            std::cout << "You do not own this property to give" << std::endl;
            return false;
        }
    }

    if(!recieveTransform){
        std::vector<BoardPiece*> otherProperties = p->getProperties();
        for(auto & i : otherProperties){
            if(i->getId() == recieve){
                hasRecieve = true;
                recieveProperty = i;
                break;
            }
        }
        if(!hasRecieve){
            std::cout << p->getName() <<" does not own this property" << std::endl;
            return false;
        }
    }

    if(hasGive && hasRecieve){
        giveProperty->setOwner(p);
        removeProperty(giveProperty);
        p->addProperty(giveProperty);
        recieveProperty->setOwner(this);
        p->removeProperty(recieveProperty);
        addProperty(recieveProperty);
        return true;
    }
    else if(hasGive && recieveTransform){
        if(p->getMoney() >= recieveInt){
            giveProperty->setOwner(p);
            removeProperty(giveProperty);
            p->addProperty(giveProperty);
            p->subtractMoney(recieveInt);
            addMoney(recieveInt);
            return true;
        }
    }
    else if(giveTransform && hasRecieve){
        if(getMoney() >= giveInt){
            subtractMoney(giveInt);
            p->addMoney(giveInt);
            recieveProperty->setOwner(this);
            p->removeProperty(recieveProperty);
            addProperty(recieveProperty);
            return true;
        }
        
    }
    else if(giveTransform && recieveTransform){
        std::cout << "Cannot offer to give and recieve money" << std::endl;
    }

    return false;
}

void Player::setPosition(int pos){
    position += pos;
}

void Player::showAssets(){

}
