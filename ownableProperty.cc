#include "ownableProperty.h"


OwnableProperty::OwnableProperty(std::string name, std::string id, int cost, int improvementCost, std::vector<int> tuition, int position, bool isGym, bool isResidence, int propertiesInSet, int row, int col): 
    BoardPiece{name, id, cost, improvementCost, tuition, position, isGym, isResidence, propertiesInSet, true, row, col}{}

bool OwnableProperty::mortgage(Player* p){
    if(!this->mortgaged && this->improvementTier == 0 && p == this->ownedPlayer){
        int morgageMoney = this->cost/2;
        p->addMoney(morgageMoney);
        this->mortgaged = true;
        return true;
    }
    return false;
}

bool OwnableProperty::unmortgage(Player* p){
    if(this->mortgaged && p == this->ownedPlayer){
        int morgageMoney = this->cost*0.6;
        //player gets money withdrawed
        if(p->getMoney() >= morgageMoney){
            p->subtractMoney(morgageMoney);
            this->mortgaged = false;
            return true;
        }
    }
    return false;
}

bool OwnableProperty::improve(Player* p){
    if(p == this->ownedPlayer){
        std::vector<BoardPiece*> properties = p->getProperties();
        int sameIdCount = 0;
        for(auto & i : properties){
            if(i->getId() == this->id){
                sameIdCount++;
            }
        }
        if(sameIdCount == this->propertiesInSet && p->getMoney() >= this->improvementCost && this->improvementTier < 5){
            p->subtractMoney(this->improvementCost);
            this->improvementTier++;
            return true;
        }
        else if(this->improvementTier == 5){
            std::cout << "This property already has 5 improvements" << std::endl;
        }
        else if(p->getMoney() < this->improvementCost){
            std::cout << "You do not have the money to improve" << std::endl;
        }
    }  
    return false;
}

bool OwnableProperty::sellImprovement(Player* p){
    if(p == this->ownedPlayer && this->improvementTier > 0){
        int refund = this->improvementCost/2;
        p->addMoney(refund);
        this->improvementTier--;
        return true;
    }
    return false;
}

// need to implement residences/gyms
void OwnableProperty::landedOn(Player* p){
    if(owned && !mortgaged){
        this->tuitionPaid = true;
        int tuitionRequired = 0;
        //calculate number of residences
        if(this->residence){
            std::vector<BoardPiece*> properties = this->ownedPlayer->getProperties();
            int residences = 0;
            for(auto & i : properties){
                if(i->isResidence()){
                    residences++;
                }
            }
            if(residences == 1){
                tuitionRequired = 25;
            }
            else if(residences == 2){
                tuitionRequired = 50;
            }
            else if(residences == 3){
                tuitionRequired = 100;
            }
            else if(residences == 4){
                tuitionRequired = 200;
            }
        }
        //gym
        else if (this->gym){
            std::vector<BoardPiece*> properties = this->ownedPlayer->getProperties();
            int gyms = 0;
            for(auto & i : properties){
                if(i->isGym()){
                    gyms++;
                }
            }

            std::vector<int> v = {1,2,3,4,5,6};
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
            int roll1 = v[0];
            std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
            int roll2 = v[0];
            std::cout << "Rolled " << roll1 << " and " << roll2 << std::endl;
            if(gyms == 2){
                tuitionRequired = 10*(roll1+roll2);
            }
            else{
                tuitionRequired = 4*(roll1+roll2);
            }
        }
        else{
            //determine the cost of tuition
            //if there are improvements
            if(this->improvementTier > 0){
                tuitionRequired = tuition[this->improvementTier];
            }
            //if there are no improvements, check if full set is owned
            else{
                std::vector<BoardPiece*> properties = this->ownedPlayer->getProperties();
                int sameIdCount = 0;
                for(auto & i : properties){
                    if(i->getId() == this->id){
                        sameIdCount++;
                    }
                }
                if(sameIdCount == this->propertiesInSet){
                    tuitionRequired = tuition[0]*2;
                }
                else{
                    tuitionRequired = tuition[0];
                }
            }
        }

        //exchange tuition
        if(p->getMoney() >= tuitionRequired){
            p->subtractMoney(tuitionRequired);
            ownedPlayer->addMoney(tuitionRequired);
            this->tuitionPaid = true;
        }
        else{
            //Game class should allow Player to make enough money to pay, or bankrupt 
            this->tuitionPaid = false;
        }
    }
    else if(owned && !mortgaged){
        std::cout << "This property is mortgaged" << std::endl;
    }
    else if(!owned){
        std::cout << "Would you like to purchase " << this->getName() << " for $" << this->getPrice() << "? (y/n)" << std::endl;
        std::string input;
        while(true){
            std::getline(std::cin, input);
            if(input == "y" || input == "n"){
                break;
            }
            else{
                std::cout << "Please enter y or n" << std::endl;
            }
        }
        if(input == "y"){
            if(p->getMoney() >= this->cost){
                p->addProperty(this);
                p->subtractMoney(this->cost);
                this->owned = true;
                this->ownedPlayer = p;
                std::cout << "Purchased" << std::endl;
            }
            else{
                std::cout << "You do not have enough money to purchase this property" << std::endl;
                //Game class will enter an auction
            }
        }
    }
}
