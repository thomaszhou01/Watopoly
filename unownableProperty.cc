#include "unownableProperty.h"

UnownableProperty::UnownableProperty(std::string name, int position):
    BoardPiece{name, "", 0, 0, {}, position, false, false, 0, true}{}


void UnownableProperty::landedOn(Player* p){

}

UnownableProperty::~UnownableProperty(){}
