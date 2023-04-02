#include "unownableProperty.h"

int UnownableProperty::generateRandom(int begin, int end, int range){
    std::vector<int> v;
    for(int i = 0; i < range; i++){
        v.push_back(i);
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(v.begin(), v.end(), std::default_random_engine(seed));
    return v[0];
}


UnownableProperty::UnownableProperty(std::string name, int position):
    BoardPiece{name, "", 0, 0, {}, position, false, false, 0, false}{}


void UnownableProperty::landedOn(Player* p){

}

UnownableProperty::~UnownableProperty(){}
