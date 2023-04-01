#ifndef UNOWNABLEPROPERTY_H
#define UNOWNABLEPROPERTY_H
#include "boardPiece.h"

class UnownableProperty: public BoardPiece{
    public:
        UnownableProperty(std::string name, int position);
        void landedOn(Player* p) override;
};

#endif
