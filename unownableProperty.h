#ifndef UNOWNABLEPROPERTY_H
#define UNOWNABLEPROPERTY_H
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include "boardPiece.h"

class UnownableProperty: public BoardPiece{
    int generateRandom(int range);
    void Tuition(Player* p);
    void CoopFee(Player* p);
    void SLC(Player* p);
    void NeedlesHall(Player* p);

    public:
        UnownableProperty(std::string name, int position);
        void landedOn(Player* p) override;
        ~UnownableProperty() override;
};

#endif
