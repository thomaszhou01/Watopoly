#include "player.h"
#include "boardPiece.h"

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

void Player::setBankrupt(Player* p){
    if(p != nullptr){
        p->addMoney(this->money);

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
    rollUpTheRimCards += number;
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

    if(!giveTransform){
        for(auto & i : this->properties){
            if(i->getId() == give){
                hasGive = true;
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
                break;
            }
        }
        if(!hasRecieve){
            std::cout << p->getName() <<" does not own this property" << std::endl;
            return false;
        }
    }


    return false;
}

void Player::setPosition(int pos){
    position += pos;
}

void Player::showAssets(){

}
