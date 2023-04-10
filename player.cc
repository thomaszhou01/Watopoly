#include "player.h"
#include "boardPiece.h"

int Player::rollupCardsGiven = 0;

Player::Player(std::string name, char character): name{name}, character{character}, position{0}, money{1500}, bankrupt{false}, inTims{false}, turnsInTims{0}, rollUpTheRimCards{0}{}

std::string Player::getName(){
    return name;
}

char Player::getCharacter(){
    return character;
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
bool Player::setBankrupt(Player* p){
    if(p != nullptr){
        p->addMoney(this->money);
        for(auto & i : this->properties){
            i->setOwner(p);
            p->addProperty(i);
            if(i->isMortgaged()){
                std::cout << "Would you like to unmortgage " << i->getName() << "? (y or n)" << std::endl;
                std::string input;
                while(true){
                    getline(std::cin, input);
                    if(input == "y" || input == "n"){
                        break;
                    }
                    else{
                        std::cout << "Please enter y or n" << std::endl;
                    }
                }
                if(input == "y"){
                    std::cout << "Unmortgaged "<< i->getName() << std::endl;
                    i->unmortgage(p);
                }
                else if(input == "n"){
                    p->subtractMoney(i->getPrice()*0.1);
                }
            }
        }
        p->setRollUpTheRimCards(p->getRollUpTheRimCards() + rollUpTheRimCards);
        return true;
    }
    else{
        for(auto & i : this->properties){
            i->reset();
        }
        return false;
    }

    bankrupt = true;
}

bool Player::isInTims(){
    return inTims;
}

void Player::reduceTimsTime(){
    turnsInTims = turnsInTims+1;
}

void Player::sendToTims(){
    position = 10;
    inTims = true;
    turnsInTims = 0;
}

int Player::getRollUpTheRimCards(){
    return rollUpTheRimCards;
}

void Player::setRollUpTheRimCards(int number){
    rollUpTheRimCards = number;
}

void Player::setMoney(int newMoney) {
    money = newMoney;
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
    std::string giveId;
    std::string recieveId;
    int givePropertyImprovements = 0;
    int recievePropertyImprovements = 0;

    //check if player has the property to give
    if(!giveTransform){
        for(auto & i : this->properties){
            if(i->getName() == give){
                hasGive = true;
                giveProperty = i;
                giveId = giveProperty->getId();
                break;
            }
        }
        if(!hasGive){
            std::cout << "You do not own this property to give" << std::endl;
            return false;
        }
        for(auto & i : this->properties){
            if(i->getId() == giveId){
                givePropertyImprovements += i->getImprovementLevel();
            }
        }
        if(givePropertyImprovements != 0){
            std::cout << "Cannot trade, improvement level of all properties in monopoly is not 0" << std::endl;
            return false;
        }
    }

    if(!recieveTransform){
        std::vector<BoardPiece*> otherProperties = p->getProperties();
        for(auto & i : otherProperties){
            if(i->getName() == recieve){
                hasRecieve = true;
                recieveProperty = i;
                recieveId = recieveProperty->getId();
                break;
            }
        }
        if(!hasRecieve){
            std::cout << p->getName() <<" does not own this property" << std::endl;
            return false;
        }
        for(auto & i : this->properties){
            if(i->getId() == recieveId){
                recievePropertyImprovements += i->getImprovementLevel();
            }
        }
        if(recievePropertyImprovements != 0){
            std::cout << "Cannot trade, improvement level of all properties in monopoly is not 0" << std::endl;
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
        else{
            std::cout << p->getName() << " does not the money to give" << std::endl;
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
        else{
            std::cout << getName() << " does not the money to give" << std::endl;
        }
        
    }
    else if(giveTransform && recieveTransform){
        std::cout << "Cannot offer to give and recieve money" << std::endl;
    }

    return false;
}

void Player::setPosition(int pos){
    position = pos;
}

void Player::showAssets(){
    std::cout << name << "'s assets" << std::endl;
    std::cout <<"Money: " << this->money << std::endl;
    std::cout << "Properties: ";
    for(auto & i : this->properties){
        std::cout << i->getName() << " ";
    }
    std::cout << std::endl << "RollUpTheRim Cards: " << rollUpTheRimCards << std::endl;
}

int Player::getTurnsInTims() {
    return turnsInTims;
}
void Player::setTurnsInTims(int i) {
    turnsInTims = i;
}

int Player::setInTims(bool option) {
    inTims = option;
    return inTims;
}
