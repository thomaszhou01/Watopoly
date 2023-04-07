#ifndef UNOWNABLEPROPERTY_H
#define UNOWNABLEPROPERTY_H
#include "boardPiece.h"

class UnownableProperty: public BoardPiece{
    int generateRandom(int range);
    void Tuition(Player* p);
    void CoopFee(Player* p);
    void SLC(Player* p);
    void NeedlesHall(Player* p);

    public:
        UnownableProperty(std::string name, int position, int row, int col);
        void landedOn(Player* p) override;
};

#endif
