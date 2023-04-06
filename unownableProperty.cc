#include "unownableProperty.h"

int UnownableProperty::generateRandom(int range){
    std::vector<int> v;
    for(int i = 0; i < range; i++){
        v.push_back(i);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
    return v[0];
}


UnownableProperty::UnownableProperty(std::string name, int position, int row, int col):
    BoardPiece{name, "", 0, 0, {}, position, false, false, 0, false, row, col}{}

void UnownableProperty::Tuition(Player* p){
    this->tuitionPaid = true;
    std::vector<BoardPiece*> properties = p->getProperties();
    int total = 0;
    total += p->getMoney();
    for(auto & i : properties){
        total += i->getPrice();
        total += i->getImprovementLevel()*i->getImprovementCost();
    }
    total = total*0.1;
    std::cout << "Would you like to pay $300 in tuition, or 10% of your total worth (which is $" << total << ")? (1 for tuition, 2 for 10%)" << std::endl;
    std::string input;
    while(true){
        std::cin >> input;
        if(input == "1" || input == "2"){
            break;
        }
        else{
            std::cout << "Please enter 1 or 2" << std::endl;
        }
    }
    std::cin.ignore();
    if(input == "1"){
        total = 300;
    }

    if(p->getMoney() >= total){
        p->subtractMoney(total);
    }
    else{
        this->tuitionPaid = false;
        //In game class, add logic to allow player to mortgage, sell, to pay
    }
}

void UnownableProperty::CoopFee(Player* p){
    if(p->getMoney() >= 150){
        p->subtractMoney(150);
    }
    else{
        this->tuitionPaid = false;
        //In game class, add logic to allow player to mortgage, sell, to pay
    }
}

void UnownableProperty::SLC(Player* p){
    int randomNum = generateRandom(24);
    int getRollUptheRim = generateRandom(100);
    if(getRollUptheRim == 0  && Player::rollupCardsGiven < 4){
        p->setRollUpTheRimCards(p->getRollUpTheRimCards()+1);
        Player::rollupCardsGiven++;
    }
    else if(randomNum >= 0 && randomNum < 3){
        p->setPosition(p->getPosition()-3 >= 0 ? p->getPosition()-3 : p->getPosition()-3 + 40);
    }
    else if(randomNum >= 3 && randomNum < 7){
        p->setPosition(p->getPosition()-2 >= 0 ? p->getPosition()-2 : p->getPosition()-2 + 40);
    }
    else if(randomNum >= 7 && randomNum < 11){
        p->setPosition(p->getPosition()-1 >= 0 ? p->getPosition()-1 : p->getPosition()-1 + 40);
    }
    else if(randomNum >= 11 && randomNum < 14){
        p->setPosition(p->getPosition()+1 < 40 ? p->getPosition()+1 : p->getPosition()+1 - 40);
    }
    else if(randomNum >= 14 && randomNum < 18){
        p->setPosition(p->getPosition()+2 < 40 ? p->getPosition()+2 : p->getPosition()+2 - 40);
    }
    else if(randomNum >= 18 && randomNum < 22){
        p->setPosition(p->getPosition()+3 < 40 ? p->getPosition()+3 : p->getPosition()+3 - 40);
    }
    else if(randomNum >= 22 && randomNum < 23){
        p->sendToTims();
    }
    else{
        p->setPosition(0);
        p->addMoney(200);
    }

}

void UnownableProperty::NeedlesHall(Player* p){
    int randomNum = generateRandom(18);
    int getRollUptheRim = generateRandom(100);
    int valueRequired = 0;
    bool gain = false;
    if(getRollUptheRim == 0  && Player::rollupCardsGiven < 4){
        p->setRollUpTheRimCards(p->getRollUpTheRimCards()+1);
    }
    else if(randomNum >= 0 && randomNum < 1){
        valueRequired = 200;
        gain = false;
    }
    else if(randomNum >= 1 && randomNum < 3){
        valueRequired = 100;
        gain = false;
    }
    else if(randomNum >= 3 && randomNum < 6){
        valueRequired = 50;
        gain = false;
    }
    else if(randomNum >= 6 && randomNum < 12){
        valueRequired = 25;
        gain = true;
    }
    else if(randomNum >= 12 && randomNum < 15){
        valueRequired = 50;
        gain = true;
    }
    else if(randomNum >= 15 && randomNum < 17){
        valueRequired = 100;
        gain = true;
    }
    else{
        valueRequired = 200;
        gain = true;
    }
    
    if(gain){
        p->addMoney(valueRequired);
    }
    else{
        if(p->getMoney() >= valueRequired){
            p->subtractMoney(valueRequired);
        }
        else{
            p->subtractMoney(p->getMoney());
        }
    }

}

void UnownableProperty::landedOn(Player* p){
    if(this->name == "COLLECT OSAP"){
        //Implement this in game class
    }
    else if(this->name == "DC Tims Line"){
        //Nothing happens if a player lands on this square
    }
    else if(this->name == "GO TO TIMS"){
        p->sendToTims();
    }
    else if(this->name == "Goose Nesting"){
        //nothing happens
    }
    else if(this->name == "TUITION"){
        Tuition(p);
    }
    else if(this->name == "COOP FEE"){
        CoopFee(p);
    }
    else if(this->name == "SLC"){
        SLC(p);
    }
    else if(this->name == "NEEDLES HALL"){
        NeedlesHall(p);
    }

}

UnownableProperty::~UnownableProperty(){}
